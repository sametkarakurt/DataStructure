/**
* @file			AVLTree.hpp
* @description	AVLTree Class'ı burada bulunur
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
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
    void insert(DogruKuyrugu* queue);
    void postOrder();
private:
    AVLNode *root;
    AVLNode* insert(DogruKuyrugu* queue,AVLNode* aktifDugum);
	AVLNode* swapLeft(AVLNode* dugum);
	AVLNode* swapRight(AVLNode* dugum);
    int height(AVLNode* currentNode);
    void postOrder(AVLNode* currentNode);
    void deleteQueues(AVLNode* currentNode);
};

#endif