#include <iostream>
#include <cmath>

class PersegiPanjang
{
  private:
    double xmin, ymin, xmax, ymax;
  public:
    PersegiPanjang(double xmid, double ymid, double xlen, double ylen);
    void set(double _xmin, double _ymin, double _xmax, double _ymax);
    double getArea();
    bool overlap(PersegiPanjang p2);
    PersegiPanjang add(PersegiPanjang p2);
    PersegiPanjang subtract(PersegiPanjang p2);
    PersegiPanjang operator+(PersegiPanjang const& p2);
    PersegiPanjang operator-(PersegiPanjang const& p2);
    bool operator==(PersegiPanjang const& p2);
    double& operator[](int i);
    PersegiPanjang operator++();      // preIncrement
    PersegiPanjang operator++(int);   // postIncrement
    PersegiPanjang operator--();
    PersegiPanjang operator--(int);
};
std::ostream& operator<<(std::ostream& os, PersegiPanjang p);