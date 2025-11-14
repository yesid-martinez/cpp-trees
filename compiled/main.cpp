#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
using namespace std;

struct Node{
	int info;
	Node * left, * right;
};

int weight = 3; // Nodes quantity - Simple binary tree by default
Node* root = nullptr;

bool isEmpty(Node * node){
	if(node == nullptr){
		return true;
	}
	if(100 > node->info > 999){
		cout << node->info << endl;
		return true;	
	}
	return false;
}

Node* createTree(Node * root){
    if(isEmpty(root)){
        Node * root = new Node();
        cout << "New node created!" << endl;
        root->info = 111;
        return root;
    }
    return root;
};

void printTree(Node * node){
	if(isEmpty(node)){
		cout <<"There is no nodes to print" << endl;
		return;
	}
	cout << node->info << endl;
}

void deleteTree(Node* node) {
    if (node == nullptr) return;
    
    deleteTree(node->left);
    deleteTree(node->right);
    
    delete node;
    
    cout << "Root have been deleted!" << endl;
}

void updateWeight(){
	string opt;
		            
	cout << "\n" << endl;
    cout << "Current tree weight: " << weight << endl;
	cout << "Do you want to change weight value?  Yes (y) or Not (n)" << endl;
	getline(cin, opt);
	
	char upperOpt = toupper(opt[0]);

	switch(upperOpt){
		case 'Y':{
			string input;
			int value;
			
			cout << "\n" << endl;
			cout << "Enter new weight value: ";
			getline(cin, input);
		
			stringstream ss(input);
			ss >> value;
	        if (!value || value < 0) {
	    		cout << "\n" << endl;
				cout << "Invalid input!  Enter positive integer value." << endl;
				break;
			}
			
			weight = value;
			cout << "\n" << endl;
			cout << "Weight updated successfully!" << endl;
			cout << "New weight value: " << weight << endl;
		}
		break;
		case 'N':
			cout << "\n" << endl;
			cout << "Got it!" << endl;
		break;
		default:
			cout << "\n" << endl;
			cout << "Invalid input!  Enter (y) or (n)" << endl;
		break;
	}
}

int main(int argc, char** argv) {
	string input;
	int option;
    
    do{
    	option = 0;
    	cout << "\n" << endl;
    	cout << " -- MAIN OPTIONS -- " << endl;
        cout << "1. Tree Weight" << endl;
        cout << "2. Create tree" << endl;
		cout << "3. Print Tree" << endl;
        cout << "4. Pre-order" << endl;
        cout << "5. In-order" << endl;
        cout << "6. Post-order" << endl;
        cout << "7. Print tree properties" << endl;
        cout << "8. Print leaf nodes" << endl;
        cout << "9. Delete tree" << endl;
        cout << "10. Close application" << endl;
    	cout << "\n" << endl;
        cout << " - Select a option: ";
        getline(cin, input);
        
        stringstream ss(input);
        ss >> option;
        
		switch(option){
            case 1:
            	updateWeight();
            break;
            case 2:
                cout << " -- Create tree -- " << endl;
                root = createTree(root);
            break;
            case 3:
                cout << " -- Print Tree -- " << endl;
                printTree(root);
            break;
            case 4:
            	cout << " -- Pre-order -- " << endl;
            break;
            case 5:
            	cout << " -- In-order -- " << endl;
            break;
            case 6:
            	cout << " -- Post-order -- " << endl;
            break;
            case 7:
            	cout << " -- Print tree properties -- " << endl;
            break;
            case 8:
            	cout << " -- Print leaf nodes -- " << endl;
            break;
            case 9:
            	cout << " -- Delete tree -- " << endl;
            	deleteTree(root);
            	root = nullptr;
            break;
            case 10:
            	cout << "\n" << endl;            
                cout << " - Finishing program..." << endl;
            	cout << "\n" << endl;
			break;
            default:
            	cout << "\n" << endl;
            	cout << "Invalid input! Select a valid option." << endl;
            break;
        }    
    }while(option != 10);
	return 0;
}
