#include "test_fft.h"

#include "fft.h"
#include "frand.h"
#include "debug.h"

/*#lake:stop*/

namespace lwml_test {

const int len = 1024;

bool test_fft(){
  frand rnd;

  vector xr0(len), xi0(len), xr(len), xi(len);
  for( int  j = 0; j < len; j++ ){
    xr[j] = xr0[j] = rnd.get_real();
    xi[j] = xi0[j] = rnd.get_real();
  }

  fft::cfft(xr, xi);

  real err = 0.0;
  for( int  j = 0; j < len; j++ ){
    cmplx spv = fft::simple_dft(xr0, xi0, j);
    err += (spv - cmplx(xr[j], xi[j])).norm();
  }

  zzz("fft: error=%lg", err);

  xr0 = xr;
  xi0 = xi;
  fft::cifft(xr, xi);

  real ierr = 0.0;
  for( int  j = 0; j < len; j++ ){
    cmplx spv = fft::simple_idft(xr0, xi0, j);
    ierr += (spv - cmplx(xr[j], xi[j])).norm();
  }

  zzz("ifft: error=%lg", ierr);

  return err < 1e-10 && ierr < 1e-10;
}

}; // namespace lwml_test
