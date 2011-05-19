#include "test_lu3d.h"

#include "frand.h"
#include "lud.h"
#include "gj3d.h"
#include "debug.h"

/*#lake:stop*/

namespace lwml_test {

const int n = 47;

bool test_lu3d()
{
  matrix a(n, n);
  vector b(n);

  a.set_zero();
  frand rnd;
  for( int j = 0; j < n; j++ ){
    a(j, j) = rnd.get_real();
    if( j != 0 )
      a(j, j-1) = rnd.get_real();
    if( j != n-1 )
      a(j, j+1) = rnd.get_real();
    b[j] = rnd.get_real();
  }

  b.set_zero();
  for( int s = 0; s < n; s++ ){
    real sum = 0;
    for( int j = 0; j < n; j++ )
      sum += a(s, j);
    b[s] = sum;
  }

  vector dd(b);
  vector aa(n-1), bb(n), cc(n-1);
  for( int j = 0; j < n; j++ )
    bb[j] = a(j, j);
  for( int j = 0; j < n-1; j++ ){
    aa[j] = a(j+1, j);
    cc[j] = a(j, j+1);
  }

  lud lu(n);
  lu.put(a);
  lu.solve(b);
  // b - решение из lud

  gj3d lu3(n);
  vector x(n);
  lu3.calc(x, aa, bb, cc, dd);
  // x - решение по gj3d

  vector x0(n, 1.0);

  real lud_err = vector::dist(b, x0);
  real gj3d_err = vector::dist(x, x0);

  zzz("lu3d: gj3d_err=%lg lud_err=%lg", gj3d_err, lud_err);

  return vector::dist(b, x) < 10.0 * lud_err;
}

}; // namespace lwml_test
