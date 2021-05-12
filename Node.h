/**
    ECE250
    Polynomial.h
    Purpose: Class to represent a polynomial with a single variable.
    Provides services to add, multiply and evaluate two polynomials.

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

// Polynomial for single variable X

class Node {

    // class variables
	private:
		double    coeff;  // coefficients
		Node *p_next_node;  // address of next node


    // class functions
    public:
    Node (double coeff[], int counter, int size);
    Node (Node *coeff);
    ~Node();


    Node *get_next();
    double get_value();



};

#endif
