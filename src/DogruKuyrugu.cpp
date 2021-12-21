/**
* @file			DoublyLinkedList.cpp
* @description	İki yönlü bağıl listenin metodlarının tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "DogruKuyrugu.hpp"
#include <string>
#include <math.h>
using namespace std;


DogruKuyrugu::DogruKuyrugu()
{
    first = last = 0;
    length = 0;
    numberOfPoint = 0;
}

DogruKuyrugu::~DogruKuyrugu(){


    while(first != NULL){
        Node* temp = first;
        first = first->next ;
        delete temp;
        
    }
}

Node* DogruKuyrugu::getLowestNode(){

	Node* prevNode = nodeBeforeLowest();
	
	if(prevNode)
		return prevNode->next;
	if(first!=0)
		return first;
    throw std::out_of_range("Kuyruk Bos");
}

void DogruKuyrugu::printNodes(){
    Node* temp = first;
    for (int i = 0; i < numberOfPoint; i++)
    {
        cout<<temp->data.distance;
        temp = temp->next;
    }
    cout<<endl;
    

}


void DogruKuyrugu::insert(int x,int y,int z){

    if(first == NULL){
        first = new Node(Nokta(x,y,z));
        last = first;
    }
    else{
        Node *newNode = new Node(Nokta(x,y,z));
        last->next = newNode;
        last = newNode;
       
    }
 
    numberOfPoint++;

}


Node* DogruKuyrugu::nodeBeforeLowest(){

    // Nokta yok
    if(first == NULL) return 0;

    //İlk noktayı atadık 
    Node* temp = first;
    Node* prevNode = 0;

    int lowestValue = temp->data.distance;
    int counter = numberOfPoint-1;
    
    while (counter>0)
    {

        if(temp->next->data.distance < lowestValue) {
            lowestValue = temp->next->data.distance;
            prevNode = temp;
        }
        
        temp = temp->next;
        counter--;
    }
    return prevNode;

}

void DogruKuyrugu::removeLowestNode(){
    Node * prevNode = nodeBeforeLowest();
    if(prevNode){
        //son düğüm en düşükse
        if(prevNode->next == last)
            last = prevNode;
        
        Node * remove = prevNode->next;
        prevNode->next = remove->next;
        delete remove;
 
  
    }
    else{
        if(first == NULL) return;
        Node *remove = first;
        first = first->next;
        delete remove;
        
    }
    numberOfPoint--;
}

int DogruKuyrugu::calculateLength(){

    if(numberOfPoint>1){
        Node* temp = first;
        for (int i = 0; i < numberOfPoint-1; i++)
        {
            length += sqrt(pow((temp->data.coordinate_x-temp->next->data.coordinate_x),2)+pow((temp->data.coordinate_y-temp->next->data.coordinate_y),2)+pow((temp->data.coordinate_z-temp->next->data.coordinate_z),2));
            temp = temp->next;
        }
    
        return length;
    }
    else{
        return 0;
    }
    
    
}