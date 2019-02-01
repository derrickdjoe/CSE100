#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <iterator>

using namespace std;

class Entry{

	list<int> chain;

	public:

		Entry(int key){

			chain.push_front(key);

		}

		void push(int key){

			chain.push_front(key);

		}

		int find(int key){

			list<int> :: iterator iter;
			int i = 0;

			for(iter = chain.begin(); iter != chain.end(); iter++){

				if(*iter == key){

					return i;

				}

				i++;

			}

			return -1;

		}

		bool remove(int key){

			int pos = find(key);
			
			if(pos != -1){

				list<int> :: iterator iter = chain.begin();
			
				while(pos > 0){

					iter++;
					pos--;

				}

				chain.erase(iter);
				return true;

			}

			return false;

		}


		void printChain(){

			list<int> :: iterator iter;

			for(iter = chain.begin(); iter != chain.end(); iter++){

				cout << *iter << "->";

			}

		}

};

class HashTable{

	Entry **table;
	int sizeCopy = 0;

	public:

		HashTable(int size){
			
			table = new Entry*[size];
			sizeCopy = size;
			
			for(int i = 0; i < size; i++){

				table[i] = NULL;

			}
		}

		~HashTable(){
		
			for(int i = 0; i < sizeCopy; i++){
		
				if(table[i]){

					delete table[i];

				}

				delete table;

			}

		}

		string search(int key){

			int hash = key % sizeCopy;
		
			if(table[hash]){

				if(table[hash]->find(key) != -1){

					return to_string(hash) + "," + to_string(table[hash]->find(key));

				}

			}

			return "";

		}

		void insert(int key){

			int hash = key % sizeCopy;

			if(table[hash]){

				table[hash]->push(key);

			}else{

				table[hash] = new Entry(key);

			}

		}

		bool remove(int key){

			string pos = search(key);
		
			if(pos != ""){

				istringstream iss(pos);
				string token;
				getline(iss, token, ',');
				int index = stoi(token);

				if(table[index]->remove(key)){

					return true;

				}
	
			}

			return false;

		}

		void print(){

			for(int i = 0; i < sizeCopy; i++){

				cout << i << ":";

				if(table[i]){

					table[i]->printChain();

				}

				cout << ";" << endl;

			}

		}

};

int main(){

	int size;
	cin >> size;

	HashTable *table = new HashTable(size);
	
	string input;
	cin >> input;

	while(input[0] != 'e'){

		if(input[0] == 'i'){
				
			table->insert(stoi(input.substr(1)));

		}

		if(input[0] == 's'){

			int key = stoi(input.substr(1));
			string pos = table->search(key);

			if(pos != ""){

				cout << key << ":FOUND_AT" << pos << ";" << endl;

			}else{

				cout << key << ":NOT_FOUND;" << endl;

			}


		}

		if(input[0] == 'd'){

			int key = stoi(input.substr(1));

			if(table->remove(key)){

				cout << key << ":DELETED;" << endl;

			}else{

				cout << key << ":DELETE_FAILED;" << endl;

			}


		}

		if(input[0] == 'o'){

			table->print();

		}

		cin >> input;

	}

}

		
