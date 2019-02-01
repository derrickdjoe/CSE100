#include<iostream>
#define INT_MAX 2147483647

using namespace std;
			
void merge(int arr[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
		
	int arrL[n1 + 1];
	int arrR[n2 + 1];

	for(int i = 0; i < n1; i++){
		arrL[i] = arr[p + i - 1];
	}

	for(int j = 0; j < n2; j++){
		arrR[j] = arr[q + j];
	}

	arrL[n1] = INT_MAX;
	arrR[n2] = INT_MAX;

	int i = 0;
	int j = 0;

	for(int k = p - 1; k < r; k++){
		if(arrL[i] <= arrR[j]){
			arr[k] = arrL[i];
			i++;
		}else{
			arr[k] = arrR[j];
			j++;
		}
	}
}

void mergeSort(int arr[], int p, int r){
	if(p < r) {
		int q = (p + r) / 2;
		mergeSort(arr, p ,q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main(){

	int p, q, r = 0;
	int size = 0;
	cin >> size;
	int arr[size];

	for(int i = 0; i <= size; i++){
		cin >> arr[i];
	}

	mergeSort(arr, 0, size);

	for(int i = 0; i <= size - 1; i++){
		cout << arr[i] << ";";
	}
	
}
