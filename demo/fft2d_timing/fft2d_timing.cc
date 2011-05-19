#include "lwml.h"
#include "debug.h"
#include "fft2d.h"
#include "rfft2d.h"
#include "frand.h"
#include "timer.h"

using namespace lwml;

int main( int argc, char *argv[] ){
try{
  console::init(argc, argv);

  int lx = config()->get_int("lx");
  int ly = config()->get_int("ly");

  frand rnd;
  matrix xr(ly, lx), xi(ly, lx);
  matrix x0(ly, lx);
  for( int s = 0; s < ly; s++ ){
    for( int c = 0; c < lx; c++ ){
      xr(s, c) = rnd.get_real();
      xi(s, c) = 0.0;
    }
  }

  timer tm;
  fft2d::cfft(xr, xi);
  printf("cfft: time=%lf\n", tm.left());

  tm.restart();
  rfft2d::rcfft(x0);
  printf("rcfft: time=%lf\n", tm.left());

  tm.restart();
  rfft2d::crifft(x0);
  printf("crifft: time=%lf\n", tm.left());

}catch( error& err ){
  console::handlex(err);
}
}
