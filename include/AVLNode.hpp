/**
* @file			AVLNode.hpp
* @description	AVLNode Class'ı burada bulunur
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#ifndef AVLNODE_HPP_
#define AVLNODE_HPP_
#include <iostream>
#include "DogruKuyrugu.hpp"
using namespace std;

class AVLNode{
    public:
		DogruKuyrugu* queue;
		AVLNode *left, *right;
		AVLNode(DogruKuyrugu* queue);
		~AVLNode();
    
};

#endif