#include "lwml.h"
#include "mtask.h"

using namespace lwml;

class my_task : public i_tbtask {
public:
  static referer<my_task> create(){
    return referer<my_task>(new(lwml_alloc) my_task());
  }

  virtual void func( int idx ){
    //printf("%d ", idx); fflush(stdout);
    real s = 0.0;
    for( int j = 0; j < 10000000; j++ )
      s += sin(j * (idx+1.1));
    printf("%d: %f\n", idx, s); fflush(stdout);
  }
};


int main( int argc, char *argv[] ){
try{
  console::init(argc, argv);

  thread_bundle tb(4);

  referer<my_task> t = my_task::create();

  tb.calc(t, 10);

}catch( error& err ){
  console::handlex(err);
}
}
