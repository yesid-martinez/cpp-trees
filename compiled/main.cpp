#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <queue>
#include <random>

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
	// Verify trash directions
	if(100 > node->info > 999){
		cout << node->info << endl;
		return true;	
	}
	return false;
}

void deleteTree(Node *& node) {
    if (node == nullptr) return;
    
    deleteTree(node->left);
    deleteTree(node->right);
    
    delete node;
    // Fix dangling pointer
    node = nullptr;
}

// Pseudo-Random Number Generator
int PRNG() {
	constexpr int MIN_INFO = 100;
	constexpr int MAX_INFO = 999;
    
	static random_device rd; // Entropy source used to initialize the PRNG seed
	// Mersenne Twister - High-quality random engine
    static mt19937 gen(rd()); // Build MT engine with random seed from rd
    static uniform_int_distribution<int> dist(MIN_INFO, MAX_INFO); // Transform number into defined ranges

    return dist(gen);
}

Node* createTree(Node * root){
    if(isEmpty(root)){
        root = new Node();
        cout << "New node created!" << endl;
        root->info = PRNG();
        root->left = nullptr;
        root->right = nullptr;
    }else{
    	delete(root);
    	root = new Node();
    	root->info = PRNG();
	}
    return root;
}

void BFS(Node * root){
	queue<Node*> q;
	q.push(root);
    
 	int created = 1;
    int limit = weight;

    while (!q.empty() && created < limit) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr && created < limit) {
            current->left = new Node();
            current->left->info = PRNG();
            current->left->left = nullptr;
            current->left->right = nullptr;
            created++;
        }

        if (current->right == nullptr && created < limit) {
            current->right = new Node();
            current->right->info = PRNG();
            current->right->left = nullptr;
            current->right->right = nullptr;
            created++;
        }

        if (current->left)  q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void printTree(Node* node) {
    if (isEmpty(root)) {
        cout << "There is no nodes to print" << endl;
        return;
    }

    queue<Node*> q;
    q.push(node);

    cout << "Tree (BFS - level order):" << endl;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            cout << current->info << " ";

            if (current->left  != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }

        cout << endl;
    }
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
                BFS(root);
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
