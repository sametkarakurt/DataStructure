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

void AVLTree::insert(DogruKuyrugu* data)
{
    root = insert(data,root);
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
        currentNode->data->printNodes();
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
AVLNode* AVLTree::insert(DogruKuyrugu* veri,AVLNode* currentNode) 
{

    if(currentNode==0){

        return new AVLNode(veri);
    }

	else if(currentNode->data->length < veri->length)
    {
    
        currentNode->right=insert(veri,currentNode->right);
        if(height(currentNode->right)-height(currentNode->left)>1)
        {   
            
            if(veri->length>currentNode->right->data->length)
                currentNode = swapLeft(currentNode);
                
            else
            {
                currentNode->right = swapRight(currentNode->right);
                currentNode =swapLeft(currentNode);
            }
        }
    }
    else if(currentNode->data->length>veri->length)
    {
        currentNode->left = insert(veri,currentNode->left);
        if(height(currentNode->left)-height(currentNode->right)>1)
        {

            if(veri->length<currentNode->left->data->length)
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
