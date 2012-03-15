#include "test_rfft2d.h"

#include "fft2d.h"
#include "rfft2d.h"
#include "frand.h"
#include "debug.h"
#include "cmplx.h"

/*#lake:stop*/

const int len = 1024;

namespace lwml_test {

bool test_rfft2d(){
  frand rnd;

  matrix x00(len, len), x0(len, len), xr(len, len), xi(len, len);
  for( int  s = 0; s < len; s++ ){
    for( int  c = 0; c < len; c++ ){
      xr(s,c) = x0(s,c) = x00(s,c) = rnd.get_real();
      xi(s,c) = 0.0;
    }
  }

  rfft2d::rcfft(x0);
  fft2d::cfft(xr, xi);

  real err = 0.0;
  err += fabs(x0(0,0) - xr(0,0));
  err += fabs(x0(1,0) - xr(0,len/2));
  err += fabs(x0(0,len-1) - xr(len/2,0));
  err += fabs(x0(1,len-1) - xr(len/2,len/2));
  for( int j = 1; j < len/2; j++ ){
    err += (cmplx(x0(0,j), x0(1,j)) - cmplx(xr(0, j), xi(0, j))).norm();
    err += (cmplx(x0(0,len-1-j), x0(1,len-1-j)) - cmplx(xr(len/2, j), xi(len/2, j))).norm();
  }
  for( int s = 1; s < len/2; s++ ){
    int ss = 2 * s;
    for( int  c = 0; c < len; c++ )
      err += (cmplx(x0(ss,c), x0(ss+1,c)) - cmplx(xr(s,c), xi(s,c))).norm();
  }
  err /= (len * len / 4);

  zzz("rfft2d: rcfft_error=%g", err);

  rfft2d::crifft(x0);
  real err2 = matrix::dist(x0, x00);
  zzz("rfft2d: crifft_error=%g", err2);

  return err < 1e-12 && err2 < 1e-12;
}

}; // namespace lwml_test
