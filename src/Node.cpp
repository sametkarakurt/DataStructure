/**
* @file			Node.cpp
* @description	Düğümün tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	2.Odev
* @date			23.12.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "Node.hpp"
#include <iostream>
using namespace std;

Node::Node()
{
    this->next = NULL;
    this->prev = NULL;
}


Node::Node(Nokta nokta)
{
    this->data = nokta;
}

