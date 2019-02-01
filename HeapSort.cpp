#include <iostream>

using namespace std;

void swap(int arr[], int x, int y){

	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;

}

void maxHeapify(int arr[], int n, int i){

	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if(left < n && arr[left] > arr[i]){
		
		largest = left;
 
	}

	if(right < n && arr[right] > arr[largest]){
	
		largest = right;

	}

	if(largest != i){
		
		swap(arr, i, largest);
		maxHeapify(arr, n, largest);
		
	}

}

void buildMaxHeap(int arr[], int n){

	for(int i = (n / 2) - 1; i >= 0; i--){
	
		maxHeapify(arr, n, i);

	}

}

void heapSort(int arr[], int n){

	buildMaxHeap(arr, n);

	for(int i = n - 1; i >= 0; i--){

		swap(arr, i, 0);
		maxHeapify(arr, i , 0);
	
	}

}

int main(){

	int size;
	cin >> size;

	int arr[size];

	for(int i = 0; i < size; i++){
	
		cin >> arr[i];

	}

	heapSort(arr, size);

	for(int j = 0; j < size; j++){

		cout << arr[j] << ";";

	}
}
