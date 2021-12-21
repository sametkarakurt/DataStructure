/**
* @file			Node.hpp
* @description	Node Class'ı burada bulunur
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#ifndef AVLNODE_HPP_
#define AVLNODE_HPP_
#include <iostream>
#include "DogruKuyrugu.hpp"
using namespace std;

class AVLNode{
    public:
		int queueLength;
		AVLNode *left, *right;
		AVLNode(int queueLength);
      
		
};

#endif