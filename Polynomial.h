/**
    ECE250
    Polynomial.h
    Purpose: Class to represent a polynomial with a single variable.
    Provides services to add, multiply and evaluate two polynomials.

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


#include <iostream>
using namespace std;

#include "Node.h" //Class to represent linked list

// Polynomial for single variable X

class Polynomial {

    // class variables
	private:
	Node *head;  // coefficients
	int size ;  // degree + 1


    // class functions
    public:
	//sets values for empty polynomial
    void set_values (int size_p, double coeff_p[]);
    Polynomial ();
    ~Polynomial();
    int get_size();
    double *create_array();
    bool array_comparison(int size_2, double array_2[]);
    double evaluater(double input);
    //following functions help with addition and multiplication
    double *array_multiplier(double *array_1, double *array_2, int size_1, int size_2);
    double *term_multiplier(double coeff, double *array_2, int power, int size);
    double *array_adder(int min_size, int max_size,  double *array_1, double *array_2);
    Node *get_head();


//    // print the polynomial
    void print();

};

#endif
