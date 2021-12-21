/**
* @file			main.cpp
* @description	Programı başlatan yer..
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include "DogruKuyrugu.hpp"
#include "AVLTree.hpp"
using namespace std;


int main()
{
     AVLTree* tree = new AVLTree();
    // DogruKuyrugu* list = new DogruKuyrugu();

    ifstream file;

    file.open("Commands.txt");
    string row;
    while(getline(file,row))
	{
        DogruKuyrugu* list = new DogruKuyrugu();
        DogruKuyrugu* list2 = new DogruKuyrugu();

        int values[3];

        int value;
        int valueIndex;
        int counter = 0;

        do
        {

            valueIndex = row.find(" ");
            if (valueIndex == -1)
            {
                value = stoi(row.substr(0,1));
                row.erase(0,1);
       
            }else{
                value = stoi(row.substr(0,valueIndex));
                row.erase(0,valueIndex+1);
            }
            values[counter] = value;
            counter++;

            if(counter%3 == 0){
                counter = 0;
                list->insert(values[0],values[1],values[2]);
            }
            
            
        
        }while (valueIndex != -1);
    
        while(list->numberOfPoint>0){
            Node* lowestNode = list->getLowestNode();
            list2->insert(lowestNode->data.coordinate_x,lowestNode->data.coordinate_y,lowestNode->data.coordinate_z);
            list->removeLowestNode();
        }
        tree->insert(list2);
        
    }

    tree->postOrder();
}














