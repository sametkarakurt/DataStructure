/**
* @file			Node.hpp
* @description	Node Class'ı burada bulunur
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
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
    bool isEmpty();
    void print();
    Node* nodeBeforeLowest();
    Node* first;
    Node* last;
    int length;
    int numberOfPoint;
    void removeLowestNode();
    Node* getLowestNode();
    void printNodes();




};


#endif