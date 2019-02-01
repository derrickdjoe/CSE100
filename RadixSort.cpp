#include <iostream>
#include <vector>

#define V_LENGTH 10
#define MAX_NUM 4

using namespace std;

void countingSort(vector<vector<int>> &arr, int d){

	vector<vector<int>> result(arr.size());
	int c[MAX_NUM];

	for(int i = 0; i < MAX_NUM; i++){

		c[i] = 0;

	}

	for(int i = 0; i < arr.size(); i++){

		result[i] = vector<int>(V_LENGTH);

	}

	for(int i = 0; i < arr.size(); i++){

		c[arr[i][d]]++;

	}

	for(int i = 1; i < 4; i++){

		c[i] = c[i] + c[i - 1];

	}

	for(int i = arr.size() - 1; i >= 0; i--){

		result[c[arr[i][d]] - 1] = arr[i];
		c[arr[i][d]]--;

	}

	for(int i = 0; i < arr.size(); i++){

		arr[i] = result[i];
	
	}

}

void radixSort(vector<vector<int>> &arr){

	for(int i = 9; i >= 0; i--){

		countingSort(arr, i);
	
	}

}

int main(){

	int size;
	cin >> size;

	vector<vector<int>> arr(size, vector<int>(V_LENGTH));
	
	for(int i = 0; i < size; i++){

		for(int j = 0; j < V_LENGTH; j++){

			cin >> arr[i][j];

		}

	}

	radixSort(arr);

	for(int i = 0; i < size; i++){

		for(int j = 0; j < V_LENGTH; j++){

			cout << arr[i][j] << ";";

		}

		cout << endl;
	
	}

}
