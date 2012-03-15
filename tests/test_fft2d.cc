#include "test_fft2d.h"

// Это очень странный тест: он проверяет только взаимную обратимость
// двумерного преобразования

#include "fft2d.h"
#include "frand.h"
#include "debug.h"

/*#lake:stop*/

namespace lwml_test {

const int len = 512;

bool test_fft2d(){
  frand rnd;

  matrix x0(len, len), xr(len, len), xi(len, len);
  for( int  s = 0; s < len; s++ ){
    for( int  c = 0; c < len; c++ ){
      xr(s,c) = x0(s,c) = rnd.get_real();
      xi(s,c) = 0.0;
    }
  }

  fft2d::cfft(xr, xi);
  fft2d::cifft(xr, xi);

  real err = 0.0;
  for( int  s = 0; s < len; s++ ){
    for( int  c = 0; c < len; c++ ){
      err += fabs(xi(s,c));
      err += fabs(xr(s,c) - x0(s,c));
    }
  }
  err /= (len * len);

  zzz("fft2d: error=%g", err);

  return err < 1e-12;
}

}; // namespace lwml_test
