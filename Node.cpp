/**
    ECE250
    Polynomial.cpp
    Purpose: Class to represent a polynomial with a single variable.
    Provides services such as add, multiply and evaluate two polynomials.

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/



#include <iostream>
using namespace std;

#include <math.h>
using namespace std;

#include <cmath>
using namespace std;

#include "Node.h"

/**
initializes current polynomial object with values in given array 

Params:
size_p int (in) - size of array
coeff_p[] double(in) - array with coefficients ie.{1.0,3.5,4.3} - corresponding to polynomial x + 3.5x + 4.3 X**2


*/

Node::Node (double coeff[], int counter, int size) {


	if (counter == size - 1) {

	this->p_next_node = nullptr;
	this->coeff = coeff[counter];

	} else {

	this->coeff = coeff[counter];

	this->p_next_node = new Node{coeff, counter + 1, size};

	}

 }

Node::Node (Node *coeff){
	this->p_next_node = coeff->p_next_node;
	this->coeff = coeff->coeff;
}

Node::~Node(){

}

Node *Node::get_next () {
	return this->p_next_node;
}

double Node::get_value() {return coeff;}
 


