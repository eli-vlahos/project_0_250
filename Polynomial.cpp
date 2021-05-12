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

#include "Polynomial.h"
#include "Node.h" //Class to represent linked list

/**
initializes current polynomial object with values in given array 

Params:
size_p int (in) - size of array
coeff_p[] double(in) - array with coefficients ie.{1.0,3.5,4.3} - corresponding to polynomial x + 3.5x + 4.3 X**2


*/


// initializes non empty polynomial
void Polynomial::set_values (int size_p, double coeff_p[]) {
 	size = size_p;
 	int start = 0;
    head = new Node{coeff_p, start, size_p};
 }

//initializes empty polynomial
Polynomial::Polynomial(){
	size = 0;
	head = nullptr;
}

Node *Polynomial::get_head() {return head;} //get the head address
int Polynomial::get_size() {return size;} //get the size of the linked list



//creating a temporary array for the linked list to make addition, evaluation and multiplication simpler
double *Polynomial::create_array(){

	 Node* node_traverse{this->head};
	 double *array = new double[this->get_size()];
	 int counter = 0;

	 while (node_traverse != nullptr) {

		 array[counter] = node_traverse->get_value();
		 node_traverse = node_traverse->get_next();


		 counter++;

	 	 }

	 return array;
}

bool Polynomial::array_comparison(int size_2, double array_2[]){

	int size_1 = this->get_size();

	if (size_1 != size_2){

		return 0;
	}
	else{

		double *array_1 = this->create_array();

		for (int i = 0; i < size_1; i++){

			if (array_1[i] != array_2[i]){
				return 0;
			}

		}

		delete[] array_1;
	}


	return 1;

}


double Polynomial::evaluater(double input){

	double sum = 0.0;

	double *array = this->create_array();

	for (int i = 0; i < this->get_size(); i++)
	{
		sum += array[i]*pow(input,(i));
	}

	delete[] array;

	return sum;

}

//this function multiplies two arrays with each other, assuming that there is a relationship between their position and power

double *Polynomial::array_multiplier(double *array_1, double *array_2, int size_1, int size_2){


	int total_size = size_1+size_2-1;
	double *sum_array = new double[total_size];

	for (int i = 0; i < total_size; i++){
		sum_array[i] = 0.0;
	}

	for (int i = 0; i < size_1; i++){
		double *temp_array = this->term_multiplier(array_1[i], array_2, i, size_2);

		for (int j = 0; j < i+size_2; j++){
			sum_array[j] += temp_array[j];
		}

		delete[] temp_array;

	}


	return sum_array;

}

//multiplying one term of a polynomial with every term of a second

double *Polynomial::term_multiplier(double coeff, double *array_2, int power, int size){

	double *new_array = new double[size+power];

	for (int i = 0; i < size+power;i++) {
		new_array[i] = 0.0;
	}

	for (int i = 0; i < size; i++){

		new_array[i+power] = coeff*array_2[i];

	}

	return new_array;
}

//adding two arrays together
double *Polynomial::array_adder(int min_size, int max_size, double *array_1, double *array_2){

	double *new_array = new double[max_size];


	for (int i = 0; i < min_size; i++){
		new_array[i] = array_1[i] + array_2[i];

	}

	if (min_size < max_size) {
		for (int i = min_size; i < max_size; i++){
			new_array[i] = array_2[i];
		}
	}

	return new_array;


}


void Polynomial::print(){

	 Node* node_traverse{this->head};

	 while (node_traverse != nullptr) {

		 double value = node_traverse->get_value();
		 std::cout << value << std::endl;
		 node_traverse = node_traverse->get_next();


	 	 }

}


Polynomial::~Polynomial() {

	 while (head != nullptr)
	 {
		 	 Node *temp_p_head{head};
		 	 head = head->get_next();
		 	 delete temp_p_head;
	 }

}





