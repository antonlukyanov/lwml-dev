#include "test_iterstat.h"

#include "tutils.h"

#include "debug.h"
#include "iterstat.h"

/*#lake:stop*/

namespace lwml_test {

real x1[] = { 1 };                // 1
real x2[] = { 1, 3 };             // 2
real x3[] = { 1, 5 };             // 2
real x4[] = { 1,1,1,1,1, 1,1,1,1,1, 2 }; // 11
real x5[] = { 1,2,3,4,5 };        // 5

namespace {
  bool test( int id, const vector& d, real alpha, real mid, real dev, int num ){
    real emid, edev;
    int n = iter_stat::calc(d, alpha, &emid, &edev);
    real mid_err = fabs(emid - mid);
    real dev_err = fabs(edev - dev);
    zzz("istat: len=%d(%d) mid_err=%g dev_err=%g", n, num, mid_err, dev_err);
    bool is_ok = (mid_err < 1e-12 && dev_err < 1e-12 && n == num);
    if( !is_ok )
       zzz("istat fail: id=%d", id);
    return is_ok;
  }
};

#define TT( op ) if( !op ) return false;

bool test_istat()
{
  test_state st;

  vector xx1(1, x1);
  st.up(test(1, xx1, 3.0, 1.0, 0.0, 1));

  vector xx2(2, x2);
  st.up(test(2, xx2, 3.0, 2.0, 1.0, 2));

  vector xx3(2, x3);
  st.up(test(3, xx3, 3.0, 3.0, 2.0, 2));

  vector xx4(11, x4);
  st.up(test(4, xx4, 3.0, 1.0, 0.0, 10));

  vector xx5(5, x5);
  st.up(test(50001, xx5, 3.0, 3.0, sqrt(2.0), 5));
  st.up(test(50002, xx5, 0.5, 3.0, 0.0, 1));

  return st.get();
}

}; // namespace lwml_test
