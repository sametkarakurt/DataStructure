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
using namespace std;


DogruKuyrugu::DogruKuyrugu()
{
    first = last = 0;
    length = 0;
}

DogruKuyrugu::~DogruKuyrugu(){


    while(first != NULL){
        Node* temp = first;
        first = first->next ;
        delete temp;
        
    }
}

bool DogruKuyrugu::isEmpty(){
    if(first == NULL)
        return true;
    return false;
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

    length++;

}


Node* DogruKuyrugu::nodeBeforeLowest(){

    // Nokta yok
    if(first == NULL) return 0;

    //İlk noktayı atadık 
    Node* temp = first;
    Node* prevNode = 0;

    int lowestValue = temp->data.distance;
    int counter = length-1;
    
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
        cout<<remove->data.coordinate_x<<" "<<remove->data.coordinate_y<<" "<<remove->data.coordinate_z<<" ";
        prevNode->next = remove->next;
        delete remove;
  
    }
    else{
        if(first == NULL) return;
        Node *remove = first;
        cout<<remove->data.coordinate_x<<" "<<remove->data.coordinate_y<<" "<<remove->data.coordinate_z<<" ";
        first = first->next;
        delete remove;
    }
    length--;
}
