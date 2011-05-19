// g++ -O2 -ffast-math -o test_alone0 test_alone0.cc

#include "stdio.h"
#include "math.h"

inline double fsqr( double t ){ return t * t; }

// �������� ������ - �������� � ������� �� ���������� �����������.
class summer {
public:
  summer( double v = 0.0 ) : _sum(v), _cur(0.0) {}

  void reset( double v = 0.0 ) {
    _sum = v;
    _cur = 0.0;
  }

  double get() const { return _sum; }

  double add( double v ) {
    double y = v - _cur;
    double t = _sum + y;
    _cur = (t - _sum) - y;
    return _sum = t;
  }

private:
  double _sum;
  double _cur;
};


void calc( const double d[], int len, double* mid, double* dev )
{
  summer sx, sxx;
  for( int j = 0; j < len; j++ ){
    double v = d[j];
    sx.add(v);
    sxx.add(v * v);
  }

  *mid = sx.get() / len;
  printf("sx=%lg, sxx=%lg\n", sx.get(), sxx.get());

  printf("sxx/len=%.19lf, fsqr(mid)=%.19lf\n", sxx.get() / len, fsqr(*mid));
  printf("d(sxx/len)=%le, d(fsqr(mid))=%le\n", sxx.get() / len - 64009.0, fsqr(*mid) - 64009.0);
  double dd = sxx.get() / len - fsqr(*mid);
  printf("dd=%lg\n", dd);
  *dev = sqrt(dd);
}

int main( int argc, char *argv[] )
{
  const int N = 3;
  double d[N];
  for( int i = 0; i < N; ++i )
    d[i] = 253;

  double mid, dev;
  calc(d, N, &mid, &dev);
  printf("len = %d, mid=%lg, dev=%lg\n", N, mid, dev);
}
