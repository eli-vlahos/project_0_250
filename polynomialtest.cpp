/**
    ECE250
    Polynomialtest.cpp
    Purpose: Tester file for Polynonial class
    Invoke methods on polynomial class read from standard input
	and write expected output to standard output

    Author Tiuley Alguindigue
    Version 1.0  - 17/12/2019
*/

#include <iostream>
#include <vector>
#include <regex>
using namespace std;

#include "Polynomial.h" // Class to represent polynomials
#include "Node.h" // Class for nodes

void initial(std::vector<std::string> line, Polynomial &p1, Polynomial &p2, std::regex ws_re); //initializes a line
int vector_size(std::vector<string> line);
double *vector_cleaner(std::vector<std::string> line); //cleans a vector to only return
bool check_size(std::vector<string> line);


int main()
{

	string cmdline;
	getline(cin, cmdline);

	Polynomial p1;
	Polynomial p2;

	std::regex ws_re("\\s+");

	while(! cin.eof()) {


		if (cmdline == "exit"){
			return 0;
		}
		if (cmdline =="coeff_p1" && p1.get_head() != nullptr){
			p1.~Polynomial();
			Polynomial p1;
		}
		if (cmdline =="coeff_p2" && p2.get_head() != nullptr){
			p2.~Polynomial();
			Polynomial p2;
		}


		std::vector<std::string> line {
			std::sregex_token_iterator(cmdline.begin(), cmdline.end(), ws_re, -1), {}
		};

		initial(line, p1, p2, ws_re);

		getline(cin, cmdline);


	}

		return 0;

}


//used this quora
//https://www.quora.com/How-do-I-split-a-string-by-space-into-an-array-in-c++

void initial(std::vector<std::string> line, Polynomial &p1, Polynomial &p2, std::regex ws_re){


	//checks to see if size of array is true
	if(line[0] == "coeff_p1"){

		line.erase(line.begin()); //get ride of coeff_p1

		if (check_size(line))
		{
			int size = static_cast<int>(line[0][0])-48;
			line.erase(line.begin()); //gets the size of the array (which we know to be true) and then get ride of it for cleaning

			double *temp_array = vector_cleaner(line);
			p1.set_values(size, temp_array);


			delete[] temp_array;
			std::cout<<"success"<<std::endl;
		}
		else {
			std::cout<<"failure" <<std::endl;
		}

		//clean

	}
	else if (line[0] == "get"){

		line.erase(line.begin());

		double *temp_array = vector_cleaner(line);
		int size = vector_size(line);
		//get size and elements in array

		bool match = p1.array_comparison(size, temp_array);

		if (match){
			std::cout<<"success"<<std::endl;
		}
		else{
			std::cout<<"failure"<<std::endl;
		}


	}
	else if (line[0] == "eval"){

		line.erase(line.begin());

		double x = stold(line[0]);
		double result = stold(line[1]);

		if (result == p1.evaluater(x)){
			std::cout << "success" <<std::endl;
		}
		else{
			std::cout <<"failure" <<std::endl;
		}


	}
	else if (line[0] == "coeff_p2"){

		line.erase(line.begin()); //get ride of coeff_p1

		if (check_size(line))
		{
			int size = static_cast<int>(line[0][0])-48;
			line.erase(line.begin()); //gets the size of the array (which we know to be true) and then get ride of it for cleaning

			double *temp_array = vector_cleaner(line);
			p2.set_values(size, temp_array);


			delete[] temp_array;
			std::cout<<"success"<<std::endl;
		}
		else {
			std::cout<<"failure" <<std::endl;
		}

		//clean

	}
	else if (line[0] == "add"){

		line.erase(line.begin());

		int sum_size = 0;
		double *sum = 0;
		//had to initialize values

		bool equal = 1;
		int size_1 = p1.get_size();
		int size_2 = p2.get_size();
		double *array_1 = p1.create_array();
		double *array_2 = p2.create_array();
		//initializes the two arrays to be added

		if (size_1 > size_2){

			sum_size = size_1;
			sum = p1.array_adder(size_2, size_1, array_2, array_1);

			//delete arrays that were dynamically initialized
		}
		else {

			sum_size = size_2;
			sum = p1.array_adder(size_1, size_2, array_1, array_2);


		}
		//function adds arrays based on which is bigger

		delete[] array_1;
		delete[] array_2;

		double *temp_array = vector_cleaner(line);
		int size = vector_size(line);

		//check to see if size is same


		if (size != sum_size){
			equal = 0;
		}
		else{

			for (int i = 0; i < size; i++){

				//have to use an absolute function to compare strings
				if (std::abs(temp_array[i]- sum[i]) > 0.00000001){
					equal = 0;
				}
			}

		}

		if (equal){
			std::cout<<"success"<<std::endl;
		}
		else{
			std::cout<<"failure"<<std::endl;
		}

		// delete[] temp_array;
		// delete[] sum;

	}
	else if (line[0] == "mult"){

		line.erase(line.begin());

		bool equal = 1;
		int size_1 = p1.get_size();
		int size_2 = p2.get_size();
		double *array_1 = p1.create_array();
		double *array_2 = p2.create_array();

		int product_size = size_1 +size_2 - 1;
		double *product = p1.array_multiplier(array_1, array_2, size_1, size_2);

		// delete[] array_1;
		// delete[] array_2;

		double *temp_array = vector_cleaner(line);
		int size = vector_size(line);

		//check to see if size is same


		if (size != product_size){
			equal = 0;
		}
		else{

			for (int i = 0; i < size; i++){

				//have to use an absolute function to compare strings
				if (std::abs(temp_array[i]- product[i]) > 0.00000001){
					equal = 0;
				}
			}

		}

		if (equal){
			std::cout<<"success"<<std::endl;
		}
		else{
			std::cout<<"failure"<<std::endl;
		}

		// delete[] temp_array;
		// delete[] product;

	}

}

int vector_size(std::vector<string> line){

	int vector_size = static_cast<int>(line.size() - 1);

	return vector_size;
}

double *vector_cleaner(std::vector<string> line){

	line.erase(line.begin());


	int size = static_cast<int>(line.size());
	double *array = new double[size-1];

	for (int i = 0; i < size; i++){

		int p = line[i].find(";");
		std::string number = line[i].substr(0,p);

		array[i] = stold(number);

	}

	return array;

}

//used stack overflow https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int

bool check_size(std::vector<string> line){


	int polynomial_size = static_cast<int>(line[0][0])-48;
	line.erase(line.begin());
	int size = vector_size(line);

	if (polynomial_size == size){
		return true;
	}
	else {
		return false;
	}
}



