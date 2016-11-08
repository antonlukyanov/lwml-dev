#include "lwml/lwml.h"
#include "lwml/utils/timer.h"
#include "lwml/base/refcount.h"
#include "lwml/random/frand.h"
#include "lwml/m_types/vector.h"

using namespace lwml;

const int N = 1000;
const int M = 10000;

class x1 : public refcount {
public:
  static referer<x1> create() {
    return referer<x1>(new(lwml_alloc) x1());
  }

  real get( int j ) const { return _data[j]; }

  real operator[]( int j ) const { return _data[j]; }

private:
  real _data[M];
};

class x2 : public refcount {
public:
  static referer<x2> create() {
    return referer<x2>(new(lwml_alloc) x2());
  }

  virtual real get( int j ) const;

  virtual real operator[]( int j ) const { return _data[j]; }

private:
  real _data[M];
};

real x2::get( int j ) const { return _data[j]; }

#define COUNT(def, use, msg) \
  {                                      \
    def;                                 \
    tm.restart();                        \
    for( int k = 0; k < N; k++ ){        \
      real sum = 0.0;                    \
      for( int j = 0; j < M; j++ ){      \
        sum += use;                      \
      }                                  \
    }                                    \
    printf("%s=%f\n", msg, 10*tm.left());  \
  }                                      //

int main( int argc, char *argv[] ){
//try{
//  console::init( argc, argv );

  timer tm;

  COUNT(real ddd[M], ddd[j], "direct")
  COUNT(vector ddd(M), ddd[j], "vector")
  COUNT((void)0, rand(), "rand")
  COUNT(frand rnd, rnd.get_real(), "frand")
  COUNT(real xx = 2.3, sin(xx), "sin")
  COUNT(real xx = 3.4, pow(xx, 2.345), "pow")
  COUNT(real xx = 4.5, exp(2.345 * log(xx)), "exp(log())")

  COUNT(x1 xxx, xxx.get(j), "function")
  COUNT(x1 xxx, xxx[j], "operator")
  COUNT(x2 xxx, xxx.get(j), "virtual function")
  COUNT(x2 xxx, xxx[j], "virtual operator")

  COUNT(x1* xxx = new x1, xxx->get(j), "ptr function")
  COUNT(x1* xxx = new x1, (*xxx)[j], "ptr operator")
  COUNT(x2* xxx = new x2, xxx->get(j), "ptr virtual function")
  COUNT(x2* xxx = new x2, (*xxx)[j], "ptr virtual operator")

  COUNT(referer<x1> xxx = x1::create(), xxx->get(j), "ref function")
  COUNT(referer<x1> xxx = x1::create(), xxx->operator[](j), "ref operator")
  COUNT(referer<x2> xxx = x2::create(), xxx->get(j), "ref virtual function")
  COUNT(referer<x2> xxx = x2::create(), xxx->operator[](j), "ref virtual operator")

//}catch( error& er ){
//  console::handlex(er);
//}
}
