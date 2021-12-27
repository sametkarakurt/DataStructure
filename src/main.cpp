/**
* @file			main.cpp
* @description	Programı başlatan yer..
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "DogruKuyrugu.hpp"
#include "AVLTree.hpp"
using namespace std;

int main()
{
    AVLTree* tree = new AVLTree();

    ifstream file;
    file.open("Noktalar.txt");
    string row;

    while(getline(file,row))
	{
        DogruKuyrugu* queue = new DogruKuyrugu();
        DogruKuyrugu* sortedQueue = new DogruKuyrugu();

        stringstream s(row);
        string word;
  
        int counter = 0;
        int values[3];

        while (s >> word){
            values[counter] = stoi(word);
            counter++;

            if(counter%3 == 0){
                counter = 0;
                queue->insert(values[0],values[1],values[2]);
             }
        }

        sortedQueue->length = queue->calculateLength();
        while(queue->numberOfPoint>0){
            Node* lowestNode = queue->getLowestNode();
            sortedQueue->insert(lowestNode->data.coordinate_x,lowestNode->data.coordinate_y,lowestNode->data.coordinate_z);
            queue->removeLowestNode();
        }
            
        tree->insert(sortedQueue);
    }
    tree->postOrder();

    delete tree;
}














