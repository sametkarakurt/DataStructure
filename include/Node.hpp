/**
* @file			Node.hpp
* @description	Node Class'ı burada bulunur
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP_
#define NODE_HPP_
#include <iostream>
#include "Nokta.hpp"
using namespace std;

class Node{
    public:
		Nokta data;
		Node *next, *prev;
		Node();
		Node(Nokta data);
};

#endif