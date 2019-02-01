#include <iostream>
using namespace std;

int main(int argc,char **argv){

int* arr;
int size = 0;
int j = 0;
int k = 0;

cin >> size;
arr = new int[size];

for(int i = 0; i <= size - 1; i++){
	cin >> arr[i];
}

for(int i = 1; i < size; i++){
	int comp = arr[i];
	j = i - 1;

	//shift everything right that is larger than my compare 
	while(j >= 0 && arr[j] > comp){
	
		arr[j + 1] = arr[j];
		j = j - 1;
	}
	
	//put compare in the new open slot
	arr[j + 1] = comp;
	
	//prints output in sequence, creates new line each run of the main for loop
	for(int k = 0; k <= i; k++){
		cout << arr[k] << ";";
	}
	cout << endl;
}

//prints out whole sequence
/*for(int i = 0; i <= size - 1; i++){
	cout << arr[i] << ";";
}*/

}
