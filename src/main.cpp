/**
 * @file main.cpp
 * @brief 
 * Tugas Operator Overloading
 * 
 * @author 
 * Nama  : Demitrias Wilbert (demitriaswilbert@gmail.com)
 * NRP   : 5024211017
 * Kelas : Proglan A
 * 
 */

#include <iostream>
#include "PersegiPanjang.hpp"

int main()
{
    std::cout << "[-----------Demo Operator Overloading-----------]" << std::endl;
    std::cout << "Note: " << std::endl;
    std::cout << "      Seluruh display titik koordinat mengikuti" << std::endl;
    std::cout << "      format sistem koordinat cartesius yaitu (x, y)" << std::endl;
    std::cout << std::endl;
    std::cout << "[-----------------------Constructor-----------------------]" << std::endl;
    std::cout << "Construct P0 : mid (-6, -7), panjang-x: 6, panjang-y: 6" << std::endl;
    PersegiPanjang p0 = PersegiPanjang(-6, -7, 6, 6);
    std::cout << "          P0 : " << p0 << std::endl;
    std::cout << "Construct P1 : mid (0, 0), panjang-x: 10, panjang-y: 20" << std::endl;
    PersegiPanjang p1 = PersegiPanjang(0, 0, 10, 20);
    std::cout << "          P1 : " << p1 << std::endl;
    std::cout << "Construct P2 : mid (5, 4), panjang-x: 10, panjang-y: 8" << std::endl;
    PersegiPanjang p2 = PersegiPanjang(5, 4, 10, 8);
    std::cout << "          P2 : " << p2 << std::endl;
    std::cout << std::endl;

    std::cout << "[-----------------------Cek Irisan------------------------]" << std::endl;
    std::cout << "P0" << ((p0 == p1) ? "" : " Tidak") << " Beririsan dengan P1" << std::endl;
    std::cout << "P0" << ((p0 == p2) ? "" : " Tidak") << " Beririsan dengan P2" << std::endl;
    std::cout << "P1" << ((p1 == p2) ? "" : " Tidak") << " Beririsan dengan P2" << std::endl;
    std::cout << std::endl;

    std::cout << "[--------------------Gabungan / Irisan--------------------]" << std::endl;
    PersegiPanjang p3 = p1 + p2;
    std::cout << "P3 (P1 + P2) : " << p3 << std::endl;
    PersegiPanjang p4 = p1 - p2;
    std::cout << "P4 (P1 - P2) : " << p4 << std::endl;
    std::cout << std::endl;

    std::cout << "[----------------Pre Increment / Decrement----------------]" << std::endl;
    std::cout << "Saat Pre Increment P3  : " << ++p3 << std::endl;
    std::cout << "P3 Sekarang            : " << p3 << std::endl;
    std::cout << std::endl;

    std::cout << "Saat Pre Decrement P3  : " << --p3 << std::endl;
    std::cout << "P3 Sekarang            : " << p3 << std::endl;
    std::cout << std::endl;

    std::cout << "[---------------Post Increment / Decrement----------------]" << std::endl;
    std::cout << "Saat Post Increment P3 : " << p3++ << std::endl;
    std::cout << "P3 Sekarang            : " << p3 << std::endl;
    std::cout << std::endl;

    std::cout << "Saat Post Decrement P3 : " << p3-- << std::endl;
    std::cout << "P3 Sekarang            : " << p3 << std::endl;
    std::cout << std::endl;

}