#include "lwml.h"
#include "frand.h"
#include "vector.h"
#include "mdefs.h"

using namespace lwml;

const int NUM = 10000;

class simp {
public:
  simp(){
    _sum = 0.0;
    _sum2 = 0.0;
    _num = 0;
  }

  void put( real x ){
    _sum += x;
    _sum2 += x*x;
    ++_num;
  }

  real get(){
    return _sum2/_num - fsqr(_sum/_num);
  }

private:
  int _num;
  real _sum, _sum2;
};

class simp_kahan {
public:
  simp_kahan(){
    _num = 0;
  }

  void put( real x ){
    _sum.add(x);
    _sum2.add(fsqr(x));
    ++_num;
  }

  real get(){
    return _sum2.get()/_num - fsqr(_sum.get()/_num);
  }

private:
  int _num;
  summer _sum, _sum2;
};

class simp2 {
public:
  simp2(){
    _mid = 0.0;
    _mid2 = 0.0;
    _num = 0;
  }

  void put( real x ){
    _mid = (_mid * _num + x) / (_num + 1);
    _mid2 = (_mid2 * _num + x*x) / (_num + 1);
    ++_num;
  }

  real get(){
    return _mid2 - fsqr(_mid);
  }

private:
  int _num;
  real _mid, _mid2;
};

int main( int argc, char *argv[] ){
try{
  console::init(argc, argv);

  vector x(NUM);
  simp s;
  simp2 s2;
  simp_kahan sk;
  for( int j = 0; j < NUM; j++ ){
    real v = (j%2 == 0) ? 1e-6 : 1e6;
    x[j] = v;
    s.put(v);
    s2.put(v);
    sk.put(v);
  }
  x.save("x.dat");

  real m = 0.5 * (1e-6 + 1e6);
  real d = 0.5 * (fsqr(1e-6 - m) + fsqr(1e6 - m));
  printf("d: %le\n", d);

  printf("disp: %le\n", fabs(x.disp() - d));
  printf("simp: %le\n", fabs(s.get() - d));
  printf("simp2: %le\n", fabs(s2.get() - d));
  printf("kahn: %le\n", fabs(sk.get() - d));

}catch( error& er ){
  console::handlex(er);
}
}
