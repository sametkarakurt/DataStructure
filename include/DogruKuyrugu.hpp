/**
* @file			DogruKuyrugu.hpp
* @description	DogruKuyrugu Class'ı burada bulunur
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#ifndef DOGRUKUYRUGU_HPP_
#define DOGRUKUYRUGU_HPP_
#include <iostream>
#include "Node.hpp"
using namespace std;

class DogruKuyrugu
{

public:
    DogruKuyrugu();
    ~DogruKuyrugu();
    void insert(int x,int y,int z);
    Node* nodeBeforeLowest();
    Node* first;
    Node* last;
    int length;
    int numberOfPoint;
    void removeLowestNode();
    Node* getLowestNode();
    void printNodes();
    int calculateLength();

};

#endif