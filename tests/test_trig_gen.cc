#include "test_trig_gen.h"

#include "debug.h"
#include "vector.h"

#include "trig_gen.h"

/*#lake:stop*/

namespace lwml_test {

namespace {
  const real alpha = 0.1;
  const int n = 300;
  const real eps = 1e-12;
};

bool test_trig_gen()
{
  vector sins(n, 0.0), coss(n, 0.0);
  trig_gen gen(alpha);
  for( int i = 0; i < n; ++i ){
    sins[i] = fabs(sin(i*alpha)-gen.get_sin());
    coss[i] = fabs(cos(i*alpha)-gen.get_cos());
    gen.next();
  }
  real sin_err = sins.max();
  real cos_err = coss.max();
  zzz("trig_gen: sin_err=%lg, cos_err=%lg", sin_err, cos_err);
  return sin_err < eps && cos_err < eps;
}

}; // namespace lwml_test
