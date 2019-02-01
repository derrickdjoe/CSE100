#include <iostream>

#define MIN -999;

using namespace std;

void rodCutter(int prices[], int n){

	int values[n + 1];
	int cuts[n + 1];
	values[0] = 0;

	for(int i = 1; i <= n; i++){

		int max = MIN;
		
		for(int j = 0; j < i; j++){

			if(max < prices[j] + values[i - j - 1]){

				max = prices[j] + values[i - j - 1];
				cuts[i] = j + 1;
		
			}


		}

		values[i] = max;

	}

	cout << values[n] << endl;

	while(n > 0){

		cout << cuts[n] << " ";
		n = n - cuts[n];

	}

}

int main(){

	int size;
	cin >> size;

	int prices[size];
	
	for(int i = 0; i < size; i++){

		cin >> prices[i];

	}

	rodCutter(prices, size);
	
	cout << -1 << endl;

}
