#include <iostream>
using namespace std;

struct Node{
	int info;
	Node * left, * right;
	// int * left, right; // 'left' would indeed be of type int*, but 'right' would be of type int.
};

int main(int argc, char** argv) {
    std::cout << "Hello world!";
	return 0;
}
