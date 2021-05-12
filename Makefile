# List all the drivers
all: project_0

project_0: polynomialtest.cpp Polynomial.cpp Node.cpp
	g++ -std=c++11 -o project_0 polynomialtest.cpp Polynomial.cpp Node.cpp

# List all the executables under 'all:'
clean:
	rm project_0