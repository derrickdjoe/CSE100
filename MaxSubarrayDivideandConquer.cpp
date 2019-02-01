#include <iostream>
#define INT_MIN -999

using namespace std;

int findMaxCrossingSubarray(int arr[], int low, int mid, int high){
	int leftSum = INT_MIN;
	int sum = 0;
	int maxLeft = 0;
	
	for(int i = mid; i >= low; i--){
		sum = sum + arr[i];
		if(sum > leftSum){
			leftSum = sum;
			maxLeft = i;
		}
	}
	
	int rightSum = INT_MIN;
	sum = 0;
	int maxRight = 0;

	for(int j = mid + 1; j <= high; j++){
		sum = sum + arr[j];
		if(sum > rightSum){
			rightSum = sum;
			maxRight = j;
		}
	}

	return(maxLeft, maxRight, leftSum + rightSum);
}

int findMaxSubarray(int arr[], int low, int high){
	int leftLow, leftHigh, rightLow, rightHigh, crossLow, crossHigh, leftSum, rightSum, crossSum = 0;
	if(high == low){
		return(low, high, arr[low]);
	}else{
		int mid = (low + high) / 2;
		(leftLow, leftHigh, leftSum) = findMaxSubarray(arr, low, mid);
		(rightLow, rightHigh, rightSum) = findMaxSubarray(arr, mid + 1, high);
		(crossLow, crossHigh, crossSum) = findMaxCrossingSubarray(arr, low, mid, high);

	}

	if(leftSum >= rightSum && leftSum >= crossSum){
		return(leftLow, leftHigh, leftSum);
	}else if(rightSum >= leftSum && rightSum >= crossSum){
		return(rightLow, rightHigh, rightSum);
	}else{
		return(crossLow, crossHigh, crossSum);
	}
}

int main(){

	int holdhigh, holdlow, holdsum;
	int size = 0;
	cin >> size;

	int arr[size];
	for(int i = 0; i <= size - 1; i++){
		cin >> arr[i];
	}

	(holdlow, holdhigh, holdsum) = findMaxSubarray(arr, 0, size - 1);
	cout << holdsum;
	
}
		
