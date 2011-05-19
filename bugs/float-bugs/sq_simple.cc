#include <cmath>

inline double fsqr( double t ) { return t * t; }

//!! SIC: hang with g++ -O2 3.4.2

int main( int argc, char *argv[] )
{
  double s = std::sqrt(-fsqr(1.0));

  return 0;
}
