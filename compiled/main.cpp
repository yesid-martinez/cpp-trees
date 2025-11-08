#include <iostream>
using namespace std;

struct Node{
	int info;
	Node * left, * right;
	// int * left, right; // 'left' would indeed be of type int*, but 'right' would be of type int.
};

int main(int argc, char** argv) {
    int option = 0;
    
    do{
    	std::cout << " -- MAIN OPTIONS -- " << endl;
        std::cout << "1. Tree Weight" << endl;
        std::cout << "2. Create tree" << endl;
		std::cout << "3. Print Tree" << endl;
        std::cout << "4. Pre-order" << endl;
        std::cout << "5. In-order" << endl;
        std::cout << "6. Post-order" << endl;
        std::cout << "7. Print tree properties" << endl;
        std::cout << "8. Print leaf nodes" << endl;
        std::cout << "9. Delete tree" << endl;
        std::cout << "10. Close application" << endl;
    	std::cout << "\n" << endl;
        std::cout << " - Select a option: ";
        std::cin >> option;
    
        switch(option){
            case 1:
                std::cout << " -- Tree Weight -- " << endl;
            break;
            case 2:
                std::cout << " -- Create tree -- " << endl;
            break;
            case 3:
                std::cout << " -- Print Tree -- " << endl;
            break;
            case 4:
            	std::cout << " -- Pre-order -- " << endl;
            break;
            case 5:
            	std::cout << " -- In-order -- " << endl;
            break;
            case 6:
            	std::cout << " -- Post-order -- " << endl;
            break;
            case 7:
            	std::cout << " -- Print tree properties -- " << endl;
            break;
            case 8:
            	std::cout << " -- Print leaf nodes -- " << endl;
            break;
            case 9:
            	std::cout << " -- Delete tree -- " << endl;
            break;
            case 10:
                std::cout << " - Finishing program..." << endl;
            break;
        }
        
    }while(option != 10);
	return 0;
}
