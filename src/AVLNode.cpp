/**
* @file			AVLNode.cpp
* @description	AVL düğümünün tanımlamaların bulunduğu yer.
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "AVLNode.hpp"

AVLNode::AVLNode(DogruKuyrugu* queue)
{
    this->queue = queue;
    left=right=0;
}
AVLNode::~AVLNode()
{
    delete queue;
}