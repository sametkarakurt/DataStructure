/**
* @file			Node.hpp
* @description	Node Class'ı burada bulunur
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include <iostream>
#include "AVLNode.hpp"
using namespace std;

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void insert(int queueLength);
    void postOrder();
    AVLNode *root;
    int size;

private:

    AVLNode* insert(int queueLength,AVLNode* aktifDugum);
	AVLNode* swapLeft(AVLNode* dugum);
	AVLNode* swapRight(AVLNode* dugum);
    int height(AVLNode* currentNode);
    void postOrder(AVLNode* currentNode);

};


#endif