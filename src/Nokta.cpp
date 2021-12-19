/**
* @file			Node.cpp
* @description	Düğümün tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "Nokta.hpp"
#include <iostream>
#include <math.h>
using namespace std;

Nokta::Nokta()
{
    this->coordinate_x = 0;
    this->coordinate_y = 0;
    this->coordinate_z = 0;
    this->distance = 0;
}


Nokta::Nokta(int x,int y, int z)
{
    this->coordinate_x = x;
    this->coordinate_y = y;
    this->coordinate_z = z;
    this->distance = sqrt(pow(coordinate_x,2)+pow(coordinate_y,2)+pow(coordinate_z,2));
}

