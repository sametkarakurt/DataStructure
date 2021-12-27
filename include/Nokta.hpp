/**
* @file			Nokta.hpp
* @description	Nokta Class'ı burada bulunur
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/
#ifndef NOKTA_HPP_
#define NOKTA_HPP_
#include <iostream>
using namespace std;

class Nokta{
    public:
		int coordinate_x;
		int coordinate_y;
		int coordinate_z;
    int distance;
    Nokta();
    Nokta(int x,int y, int z);
};

#endif