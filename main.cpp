#include <cmath>
#include <iostream>

class PersegiPanjang
{
  private:
  public:
    double xmin, ymin, xmax, ymax;
    PersegiPanjang(double xmid, double ymid, double xlen, double ylen)
    // : xmin(xmid), ymin(ymid), xmax(xlen), ymax(ylen)
    {
        this->xmin = xmid - (xlen / 2);
        this->xmax = this->xmin + xlen;
        this->ymin = ymid - (ylen / 2);
        this->ymax = this->ymin + ylen;
    }
    void set(double _xmin, double _ymin, double _xmax, double _ymax)
    {
        this->xmin = _xmin;
        this->ymin = _ymin;
        this->xmax = _xmax;
        this->ymax = _ymax;
    }
    double getArea() { return ((xmax - xmin) * (ymax - ymin)); }

    bool overlap(PersegiPanjang p2)
    {
        if (this->xmin == this->xmax || this->ymin == this->ymax || p2.xmin == p2.xmax || p2.ymin == p2.ymax)
            return false;
        if (this->xmin >= p2.xmax || p2.xmin >= this->xmax)
            return false;
        if (this->ymin >= p2.ymax || p2.ymin >= this->ymax)
            return false;
        return true;
    }
    PersegiPanjang add(PersegiPanjang p2)
    {
        if (this->overlap(p2))
        {
            double minx = (this->xmin < p2.xmin) ? this->xmin : p2.xmin;
            double miny = (this->ymin < p2.ymin) ? this->ymin : p2.ymin;
            double maxx = (this->xmax > p2.xmax) ? this->xmax : p2.xmax;
            double maxy = (this->ymax > p2.ymax) ? this->ymax : p2.ymax;
            PersegiPanjang tmp = PersegiPanjang(0, 0, 0, 0);
            tmp.set(minx, miny, maxx, maxy);
            return tmp;
        }
        return PersegiPanjang(0, 0, 0, 0);
    }
    PersegiPanjang subtract(PersegiPanjang p2)
    {
        if (this->overlap(p2))
        {
            double minx = (this->xmin > p2.xmin) ? this->xmin : p2.xmin;
            double miny = (this->ymin > p2.ymin) ? this->ymin : p2.ymin;
            double maxx = (this->xmax < p2.xmax) ? this->xmax : p2.xmax;
            double maxy = (this->ymax < p2.ymax) ? this->ymax : p2.ymax;
            PersegiPanjang tmp = PersegiPanjang(0, 0, 0, 0);
            tmp.set(minx, miny, maxx, maxy);
            return tmp;
        }
        return PersegiPanjang(0, 0, 0, 0);
    }
    PersegiPanjang operator+(PersegiPanjang const& p2)
    {
        return this->add(p2);
    }
    PersegiPanjang operator-(PersegiPanjang const& p2)
    {
        return this->subtract(p2);
    }
    bool operator==(PersegiPanjang const& p2)
    {
        return this->overlap(p2);
    }
    double operator[](int i)
    {
        double tmp[] = {this->xmin, this->ymin, this->xmax, this->ymax};
        return tmp[i % 4];
    }
    void operator++()
    {
        double midx = (this->xmin + this->xmax) / 2;
        double midy = (this->ymin + this->ymax) / 2;
        this->xmin = midx - ((midx - this->xmin) * pow(2, 0.5));
        this->ymin = midy - ((midy - this->ymin) * pow(2, 0.5));
        this->xmax = midx + ((this->xmax - midx) * pow(2, 0.5));
        this->ymax = midy + ((this->ymax - midy) * pow(2, 0.5));
    }
    void operator++(int)
    {
        double midx = (this->xmin + this->xmax) / 2;
        double midy = (this->ymin + this->ymax) / 2;
        this->xmin = midx - ((midx - this->xmin) * pow(2, 0.5));
        this->ymin = midy - ((midy - this->ymin) * pow(2, 0.5));
        this->xmax = midx + ((this->xmax - midx) * pow(2, 0.5));
        this->ymax = midy + ((this->ymax - midy) * pow(2, 0.5));
    }
    void operator--()
    {
        double midx = (this->xmin + this->xmax) / 2;
        double midy = (this->ymin + this->ymax) / 2;
        this->xmin = midx - ((midx - this->xmin) / pow(2, 0.5));
        this->ymin = midy - ((midy - this->ymin) / pow(2, 0.5));
        this->xmax = midx + ((this->xmax - midx) / pow(2, 0.5));
        this->ymax = midy + ((this->ymax - midy) / pow(2, 0.5));
    }
    void operator--(int)
    {
        double midx = (this->xmin + this->xmax) / 2;
        double midy = (this->ymin + this->ymax) / 2;
        this->xmin = midx - ((midx - this->xmin) / pow(2, 0.5));
        this->ymin = midy - ((midy - this->ymin) / pow(2, 0.5));
        this->xmax = midx + ((this->xmax - midx) / pow(2, 0.5));
        this->ymax = midy + ((this->ymax - midy) / pow(2, 0.5));
    }
    friend std::ostream& operator<<(std::ostream& os, PersegiPanjang& p)
    {
        os << "{ min(" << p[0] << "x, " << p[1] << "y), max(" << p[2] << "x, " << p[3] << "y) }";
        return os;
    }
};

int main()
{
    PersegiPanjang p0 = PersegiPanjang(-6, -7, 6, 6);
    std::cout << "P0 : " << p0 << std::endl;
    PersegiPanjang p1 = PersegiPanjang(0, 0, 10, 20);
    std::cout << "P1 : " << p1 << std::endl;
    PersegiPanjang p2 = PersegiPanjang(5, 4, 10, 8);
    std::cout << "P2 : " << p2 << std::endl;
    PersegiPanjang p3 = p1 + p2;
    std::cout << std::endl;

    std::cout << "P0" << ((p0 == p1) ? "" : " Tidak") << " Beririsan dengan P1" << std::endl;
    std::cout << "P0" << ((p0 == p2) ? "" : " Tidak") << " Beririsan dengan P2" << std::endl;
    std::cout << "P1" << ((p1 == p2) ? "" : " Tidak") << " Beririsan dengan P2" << std::endl;
    std::cout << std::endl;

    std::cout << "P3 (P1 + P2) : " << p3 << std::endl;
    std::cout << "Luas P3 : " << p3.getArea() << std::endl;
    p3++;
    std::cout << "Increment P3 : " << p3 << std::endl;
    std::cout << "Luas P3 setelah increment : " << p3.getArea() << std::endl;
    p3--;
    std::cout << "Decrement P3 : " << p3 << std::endl;
    std::cout << "Luas P3 setelah decrement : " << p3.getArea() << std::endl;
}