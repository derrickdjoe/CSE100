#include <iostream>
#include <string>

using namespace std;

struct Node{

	Node* parent;
	Node* leftChild;
	Node* rightChild;
	int value;

	Node(int n){

		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
		value = n;

	}

	~Node(){

	}

};

class BST{

	Node* root;

	public:

		BST(){
		
			root = NULL;

		}

		~BST(){

		}


		void insert(Node* root, int n){

			if(this->root){

				if(root->value > n){

					if(!root->leftChild){

						root->leftChild = new Node(n);
						root->leftChild->parent = root;

					}else{

						insert(root->leftChild, n);

					}

				}else{

					if(!root->rightChild){

						root->rightChild = new Node(n);
						root->rightChild->parent = root;

					}else{

						insert(root->rightChild, n);

					}

				}

			}else{

				this->root = new Node(n);

			}

		}

		void preOrder(Node* root){

			if(root == NULL){

				return;

			}

			cout << root->value << endl;
			preOrder(root->leftChild);
			preOrder(root->rightChild);

		}

		void postOrder(Node* root){

			if(root == NULL){

				return;

			}

			postOrder(root->leftChild);
			postOrder(root->rightChild);
			cout << root->value << endl;

		}

		void inOrder(Node* root){

			if(root == NULL){

				return;

			}

			inOrder(root->leftChild);
			cout << root->value << endl;
			inOrder(root->rightChild);

		}

		Node* search(Node* root, int key){

			if(root == NULL || key == root->value){
		
				return root;

			}

			if(key < root->value){

				return search(root->leftChild, key);

			}else{

				return search(root->rightChild, key);

			}

		}

		Node* minimum(Node* root){

			if(!root){

				return NULL;

			}

			while(root->leftChild){

				root = root->leftChild;

			}

			return root;

		}

		Node* transplant(Node* old, Node* newNode){

			if(old->parent == NULL){

				root = newNode;

			}

			else if(old == old->parent->leftChild){

				old->parent->leftChild = newNode;

			}else{

				old->parent->rightChild = newNode;

			}

			if(newNode){

				newNode->parent = old->parent;

			}

		}

		void deleteHelper(Node* root){

			if(root->leftChild == NULL){

				transplant(root, root->rightChild);

			}

			else if(root->rightChild == NULL){

				transplant(root, root->leftChild);

			}else{

				Node* temp = minimum(root->rightChild);

				if(temp->parent != root){

					transplant(temp, temp->rightChild);
					temp->rightChild = root->rightChild;
					temp->rightChild->parent = temp;

				}

				transplant(root, temp);
				temp->leftChild = root->leftChild;
				temp->leftChild->parent = temp;

			}

		}

		void deleteNode(int key){

			Node* temp = search(this->root, key);
			if(temp){

				deleteHelper(temp);

			}

		}

		Node* getRoot(){

			return root;

		}

};

int main(){

	BST* bst = new BST();

	string input;

	cin >> input;

	while(input[0] != 'e'){

		if(input[0] == 'i'){

			bst->insert(bst->getRoot(), stoi(input.substr(1)));
		
		}

		else if(input[0] == 'd'){

			bst->deleteNode(stoi(input.substr(1)));
			//cout << "Deleted Node" << endl;

		}


		else if(input == "opre"){
			//cout<< "Doing preOrder" << endl;
			bst->preOrder(bst->getRoot());
	
		}

		else if(input == "opost"){
			//cout <<"Doing postOrder" << endl;
			bst->postOrder(bst->getRoot());

		}

		else if(input == "oin"){
			//cout << "Doing in ORder" << endl;
			bst->inOrder(bst->getRoot());

		}

		cin >> input;

	}

}
		

