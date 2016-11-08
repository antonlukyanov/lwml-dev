#include "lwml/lwml.h"

#include "tests/tutils.h"

#include "tests/test_lu3d.h"
#include "tests/test_median.h"
#include "tests/test_hooke.h"
#include "tests/test_iterstat.h"
#include "tests/test_trig_gen.h"
#include "tests/test_fft.h"
#include "tests/test_rfft.h"
#include "tests/test_fft2d.h"
#include "tests/test_rfft2d.h"
#include "tests/test_spline.h"

using namespace lwml;
using namespace lwml_test;

test_state overall;

void test( bool ok, const char* nm )
{
  overall.up(ok);
  printf("%s: %s\n", nm, ok ? "ok" : "fail");
}

#define TEST(nm) \
  test(test_##nm(), "test_" #nm);

int main( int argc, char *argv[] ){
try{
  console::init(argc, argv);

  TEST(lu3d)
  TEST(median)
  TEST(hooke)
  TEST(istat)
  TEST(rfft)
  TEST(trig_gen)
  TEST(fft)
  TEST(fft2d)
  TEST(rfft2d)
  TEST(spline)

  if( overall.get() )
    printf("--\noverall: ok\n");
  else
    printf("--\noverall: fail\n");

}catch( error& err ){
  console::handlex(err);
}
}
