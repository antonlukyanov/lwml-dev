#include "test_hooke.h"

#include "debug.h"
#include "hooke.h"

/*#lake:stop*/

namespace lwml_test {

// тестовый пример: банан Розенброка
// Rosenbrocks classic parabolic valley ("banana") function

class rosenbroke : public i_vfunction {
public:
  virtual real func( const vector& x ) const {
    real a = x[0];
    real b = x[1];
    real c = 100.0 * (b - (a * a)) * (b - (a * a));
    return (c + ((1.0 - a) * (1.0 - a)));
  }
};

bool test_hooke()
{
  vector x0(2), x(2), dx(2);

  x0[0] = -1.2;  dx[0] = 1.0;
  x0[1] = 1.0;   dx[1] = 1.0;

  rosenbroke fn;
  int jj = hooke::calc(fn, x0, x, dx, 0.5, 1e-8, 500);
  real x0_err = fabs(1.0 - x[0]);
  real x1_err = fabs(1.0 - x[1]);
  zzz("hooke: steps=%d x0_err=%g x1_err=%.2e", jj, x0_err, x1_err);
  return jj < 500 && x0_err < 1e-6 && x1_err < 1e-6;
}

}; // namespace lwml_test
