/**
* @file			DoublyLinkedList.cpp
* @description	İki yönlü bağıl listenin metodlarının tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
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

}

void AVLTree::insert(int queueLength)
{
    root = insert(queueLength,root);
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
        cout<<currentNode->queueLength<<" ";
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
AVLNode* AVLTree::insert(int queueLength,AVLNode* currentNode) 
{
    if(currentNode==0)
        return new AVLNode(queueLength);

	else if(currentNode->queueLength<queueLength)
    {
        currentNode->right=insert(queueLength,currentNode->right);
        if(height(currentNode->right)-height(currentNode->left)>1)
        {   
            if(queueLength>currentNode->right->queueLength)
                currentNode = swapLeft(currentNode);
                
            else
            {
                currentNode->right = swapRight(currentNode->right);
                currentNode =swapLeft(currentNode);
            }
        }
    }
    else if(currentNode->queueLength>=queueLength)
    {
        currentNode->left = insert(queueLength,currentNode->left);
        if(height(currentNode->left)-height(currentNode->right)>1)
        {

            if(queueLength<currentNode->left->queueLength)
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
