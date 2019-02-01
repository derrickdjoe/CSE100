#include <iostream>
#include <cstdlib>

using namespace std;

void exchange(int arr[], int x, int y){

	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;

}

int partition(int arr[], int p, int r){

	int x = arr[r];
	int i = p - 1;

	for(int j = p; j <= r - 1; j++){

		if(arr[j] <= x){
	
			i++;
			exchange(arr, i, j);

		}

	}

	exchange(arr, i + 1, r);
	return i + 1;

}

int randomizedPartition(int arr[], int p, int r){

	int i = p + rand() % (r - p);
	exchange(arr, r, i);

	return partition(arr, p, r);

}

void quickSort(int arr[], int p, int r){

	if(p < r){

		int q = randomizedPartition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);

	}

}

int main(){

	int size = 0;
	cin >> size;

	int arr[size];

	for(int i = 0; i < size; i++){

		cin >> arr[i];

	}

	quickSort(arr, 0, size - 1);

	for(int j = 0; j < size; j++){

		cout << arr[j] << ";";

	}

}
