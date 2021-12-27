/**
* @file			AVLTree.cpp
* @description	AVL ağacının metodlarının tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "AVLTree.hpp"
#include <string>
using namespace std;

AVLTree::AVLTree()
{
    root= 0;
}
AVLTree::~AVLTree()
{
    deleteQueues(root);
    root = 0;
}

void AVLTree::insert(DogruKuyrugu* queue)
{
    root = insert(queue,root);
}

AVLNode* AVLTree::insert(DogruKuyrugu* queue,AVLNode* currentNode) 
{
    if(currentNode==0)
        return new AVLNode(queue);

	else if(currentNode->queue->length<queue->length)
    {
        currentNode->right=insert(queue,currentNode->right);
        if(height(currentNode->right)-height(currentNode->left)>1)
        {   
            if(queue->length>currentNode->right->queue->length)
                currentNode = swapLeft(currentNode);
                
            else
            {
                currentNode->right = swapRight(currentNode->right);
                currentNode =swapLeft(currentNode);
            }
        }
    }
    else if(currentNode->queue->length>=queue->length)
    {
        currentNode->left = insert(queue,currentNode->left);
        if(height(currentNode->left)-height(currentNode->right)>1)
        {

            if(queue->length<currentNode->left->queue->length)
                currentNode = swapRight(currentNode);
            else
            {
                currentNode->left = swapLeft(currentNode->left);
                currentNode =swapRight(currentNode);
            }
        }

    }
    return currentNode;
  
}

AVLNode* AVLTree::swapLeft(AVLNode*parent) 
{
	AVLNode* rightChild = parent->right;
    parent->right = rightChild->left;
    rightChild->left = parent;
    return rightChild;
}
AVLNode* AVLTree::swapRight(AVLNode* parent) 
{
	AVLNode* leftChild = parent->left;
    parent->left = leftChild->right;
    leftChild->right = parent;
    return leftChild;
}

void AVLTree::postOrder() {
	postOrder(root);
}

void AVLTree::postOrder(AVLNode* currentNode) 
{
	if(currentNode)
    {
        postOrder(currentNode->left);
        postOrder(currentNode->right);
        currentNode->queue->printNodes();
    }	
}

int AVLTree::height(AVLNode* currentNode) 
{
	if(currentNode)
    {
        return 1+max(   height(currentNode->left),
                        height(currentNode->right));
    }
    return -1;
}

void AVLTree::deleteQueues(AVLNode* currentNode){
    if(currentNode!=0)
    {
        deleteQueues(currentNode->left);
        deleteQueues(currentNode->right);
        delete currentNode;
    }
}