#include "PersegiPanjang.hpp"

/**
 * @brief Constructor
 * 
 * @param xmid titik tengah x
 * @param ymid titik tengah y
 * @param xlen panjang x
 * @param ylen panjang y
 */
PersegiPanjang::PersegiPanjang(double xmid, double ymid, double xlen, double ylen)
// : xmin(xmid), ymin(ymid), xmax(xlen), ymax(ylen)
{
    this->xmin = xmid - (xlen / 2);
    this->xmax = this->xmin + xlen;
    this->ymin = ymid - (ylen / 2);
    this->ymax = this->ymin + ylen;
}

/**
 * @brief mengganti nilai secara manual
 * 
 * @param _xmin xmin baru
 * @param _ymin ymin baru
 * @param _xmax xmax baru
 * @param _ymax ymax baru
 */
void PersegiPanjang::set(double _xmin, double _ymin, double _xmax, double _ymax)
{
    this->xmin = _xmin;
    this->ymin = _ymin;
    this->xmax = _xmax;
    this->ymax = _ymax;
}

/**
 * @brief menghitung luas dari persegi panjang
 * 
 * @return double nilai luas persegi panjang
 */
double PersegiPanjang::getArea() { return ((xmax - xmin) * (ymax - ymin)); }

/**
 * @brief menentukan apakah kedua luasan persegi panjang beririsan
 * 
 * @param p2 
 * @return true kedua persegi panjang beririsan
 * @return false kedua persegi panjang tidak beririsan
 */
bool PersegiPanjang::overlap(PersegiPanjang p2)
{
    if (this->xmin == this->xmax || this->ymin == this->ymax || p2.xmin == p2.xmax || p2.ymin == p2.ymax)
        return false;
    if (this->xmin >= p2.xmax || p2.xmin >= this->xmax)
        return false;
    if (this->ymin >= p2.ymax || p2.ymin >= this->ymax)
        return false;
    return true;
}

/**
 * @brief menggabungkan kedua luasan
 * fungsi ini hanya akan bekerja jika kedua persegi panjang saling beririsan
 * jika tidak maka akan me-return persegi panjang dengan xmin, ymin, xmax, ymax bernilai 0
 * 
 * @param p2 persegi panjang lain
 * @return PersegiPanjang hasil gabungan
 */
PersegiPanjang PersegiPanjang::add(PersegiPanjang p2)
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

/**
 * @brief mengambil irisan kedua persegi panjang
 * fungsi ini hanya akan bekerja jika kedua persegi panjang saling beririsan
 * jika tidak maka akan me-return persegi panjang dengan xmin, ymin, xmax, ymax bernilai 0
 * 
 * @param p2 persegi panjang lain
 * @return PersegiPanjang hasil irisan
 */
PersegiPanjang PersegiPanjang::subtract(PersegiPanjang p2)
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

/**
 * @brief + overload
 * menggabungkan kedua luasan
 * fungsi ini hanya akan bekerja jika kedua persegi panjang saling beririsan
 * jika tidak maka akan me-return persegi panjang dengan xmin, ymin, xmax, ymax bernilai 0
 * 
 * @param p2 
 * @return PersegiPanjang baru hasil gabungan
 */
PersegiPanjang PersegiPanjang::operator+(PersegiPanjang const& p2)
{
    return this->add(p2);
}

/**
 * @brief - overload
 * mengambil irisan dari kedua luasan
 * fungsi ini hanya akan bekerja jika kedua persegi panjang saling beririsan
 * jika tidak maka akan me-return persegi panjang dengan xmin, ymin, xmax, ymax bernilai 0
 * 
 * @param p2 
 * @return PersegiPanjang baru hasil irisan
 */
PersegiPanjang PersegiPanjang::operator-(PersegiPanjang const& p2)
{
    return this->subtract(p2);
}

/**
 * @brief == overload
 * menentukan apakah kedua luasan persegi panjang beririsan
 * 
 * @param p2 
 * @return true kedua persegi panjang beririsan
 * @return false kedua persegi panjang tidak beririsan
 */
bool PersegiPanjang::operator==(PersegiPanjang const& p2)
{
    return this->overlap(p2);
}

/**
 * @brief mengambil nilai dari xmin, ymin, xmax, ymax
 * 
 * @param i xmin: 0, ymin: 1, xmax: 2, ymax: 3
 * @return double nilai dari xmin, ymin, xmax, ymax
 */
double& PersegiPanjang::operator[](int i)
{
    double* tmp[] = {&(this->xmin), &(this->ymin), &(this->xmax), &(this->ymax)};
    return *tmp[i % 4];
}

/**
 * @brief pre increment overload
 * menambah luas persegi panjang menjadi dua kali luas sebelumnya
 * dengan mengalikan panjang dan lebar dengan sqrt(2), dengan nilai titik tengah yang sama
 * 
 * @return PersegiPanjang baru dengan luas 2 kali
 */
PersegiPanjang PersegiPanjang::operator++()
{
    double midx = (this->xmin + this->xmax) / 2;
    double midy = (this->ymin + this->ymax) / 2;
    this->xmin = midx - ((midx - this->xmin) * pow(2, 0.5));
    this->ymin = midy - ((midy - this->ymin) * pow(2, 0.5));
    this->xmax = midx + ((this->xmax - midx) * pow(2, 0.5));
    this->ymax = midy + ((this->ymax - midy) * pow(2, 0.5));
    PersegiPanjang pNew = PersegiPanjang(*this);
    return pNew;
}

/**
 * @brief post increment overload
 * menambah luas persegi panjang menjadi dua kali luas sebelumnya
 * dengan mengalikan panjang dan lebar dengan sqrt(2), dengan nilai titik tengah yang sama
 * 
 * @return PersegiPanjang 
 */
PersegiPanjang PersegiPanjang::operator++(int)
{
    PersegiPanjang pNew = PersegiPanjang(*this);
    ++(*this);
    return pNew;
}

/**
 * @brief pre decrement overload
 * mengurangi luas persegi panjang menjadi setengah kali luas sebelumnya
 * dengan membagikan panjang dan lebar dengan sqrt(2), dengan nilai titik tengah yang sama
 * 
 * @return PersegiPanjang 
 */
PersegiPanjang PersegiPanjang::operator--()
{
    double midx = (this->xmin + this->xmax) / 2;
    double midy = (this->ymin + this->ymax) / 2;
    this->xmin = midx - ((midx - this->xmin) / pow(2, 0.5));
    this->ymin = midy - ((midy - this->ymin) / pow(2, 0.5));
    this->xmax = midx + ((this->xmax - midx) / pow(2, 0.5));
    this->ymax = midy + ((this->ymax - midy) / pow(2, 0.5));
    PersegiPanjang pNew = PersegiPanjang(*this);
    return pNew;
}

/**
 * @brief post decrement overload
 * mengurangi luas persegi panjang menjadi setengah kali luas sebelumnya
 * dengan membagikan panjang dan lebar dengan sqrt(2), dengan nilai titik tengah yang sama
 * 
 * @return PersegiPanjang 
 */
PersegiPanjang PersegiPanjang::operator--(int)
{
    PersegiPanjang pNew = PersegiPanjang(*this);
    --(*this);
    return pNew;
}

/**
 * @brief insertion overload
 * mencetak nilai xmin, ymin, xmax, ymax beserta luas persegi panjang ke ostream
 * 
 * @param os 
 * @param p 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, PersegiPanjang p)
{
    os << "{ min: (" << p[0] << "x, " << p[1] << "y), max: (" << p[2] << "x, " << p[3] << "y), Luas: "<< p.getArea() <<" }";
    return os;
}