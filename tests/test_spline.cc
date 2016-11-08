#include "tests/test_spline.h"

#include "lwml/utils/debug.h"
#include "lwml/m_types/vector.h"

#include "lwml/m_alg/spline.h"
#include "lwml/m_alg/lms.h"

/*#lake:stop*/

namespace lwml_test {

namespace {
  const real T = 2.0*M_PI;
  const int n = 100;
  const int addon = 3; // количество вычисляемых значений между узлами
  const int n2 = n + addon*(n-1);
  const real delta = 0.0;
  const real eps = 1.0e-12; // погрешность в узлах
  const real eps1 = (T/n)*(T/n)*(T/n); // погрешность в промежутках

  real func( real x ){
//~     return x*x*x + 2*x*x +3*x + 1;
    return cos((x-delta) / n * T);
//~     return intpow(x/10.0, 7);
  }
  real func_der2( real x ){
//~     return 6.0*(x) + 4;
    return -cos((x-delta) / n * T)  / n * T / n * T;
//~     return 42*intpow(x/10.0, 5)/100.0;
  }
};

bool test_spline()
{
  vector x(n, 0.0), y(n, 0.0);
  for( int i = 0; i < n; ++i ){
    x[i] = i;
    y[i] = func(i);
  }

  spline sp(n);
  sp.put(x, y, func_der2(0.0), func_der2(n-1));
//~   sp.put(x, y, 0.0, 0.0);

  // проверка значений в узлах
  vector knot_errs(n);
  real knot_err = 0;
  for( int i = 0; i < n; ++i ){
    real d = fabs(func(i) - sp.calc(i));
    knot_errs[i] = d;
    if( d > knot_err )
      knot_err = d;
  }
  if( zzz_dump() )
    knot_errs.save(zzz_dump_name("sp_knot_errs.dat").ascstr());

  // считаем в бОльшем числе точек
  vector val_errs(n2);
  real val_err = 0;
  for( int i = 0; i < n; ++i ){
    for( int j = 0; j <= addon; ++j ){ // дополнительные узлы в промежутках
      real x = i + j / real_cast(addon+1);
      if( x <= n-1 ){
        real d = fabs(func(x)-sp.calc(x));
        val_errs[i*(addon+1) + j] = d;
        if( d > val_err )
          val_err = d;
      }
    }
  }
  if( zzz_dump() )
    val_errs.save(zzz_dump_name("sp_val_errs.dat").ascstr());

  zzz("spline: eps=%g, eps1=%g", eps, eps1);
  zzz("spline: knot_err=%g, val_err=%g", knot_err, val_err);
  return knot_err < eps && val_err < eps1;
}

}; // namespace lwml_test
