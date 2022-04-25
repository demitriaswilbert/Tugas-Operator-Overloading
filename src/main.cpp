#include <iostream>
#include "PersegiPanjang.hpp"

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