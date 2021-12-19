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
using namespace std;


int main()
{

    // DogruKuyrugu* list = new DogruKuyrugu();

    ifstream file;

    file.open("Commands.txt");
    string row;
    while(getline(file,row))
	{
        DogruKuyrugu* list = new DogruKuyrugu();

        int values[3];
        int lastSpace = row.find_last_of(" ");
        int lastValue = stoi(row.substr(lastSpace+1,row.length()-1));
        int value;
        int counter = 0;
        int counter2 = 0;
  
   


        while(value != lastValue)
        {
            int valueIndex = row.find(" ");
            value = stoi(row.substr(0,valueIndex));
           
   
            values[counter] = value;
            counter++;
            if(counter%3 == 0){
                counter = 0;
                list->insert(values[0],values[1],values[2]);
            }
            row.erase(0,valueIndex+1);
            counter2 ++;   
        }
 
        while(list->length>0){
            list->removeLowestNode();
        }
        cout <<endl;

        
    }

}














