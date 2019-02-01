#include <iostream>
#include <climits>

using namespace std;

void printOptimalParens(int* s, int i, int j, int n){

	if(i == j){

		cout << "A" << i - 1;
		return;

	}

	cout << "(";
	printOptimalParens(s, i, *((s + i * n) + j), n);
	printOptimalParens(s, *((s + i * n) + j) + 1, j, n);
	cout << ")";

}

void matrixChainOrder(int arr[], int n){

	int m[n][n], s[n][n];

	for(int i = 1; i < n; i++){

		m[i][i] = 0;

	}

	for(int i = 2; i < n; i++){

		for(int j = 1; j < n - i + 1; j++){

			int k = i + j - 1;
			m[j][k] = INT_MAX;

			for(int l = j; l < k; l++){

				int q = m[j][l] + m[l + 1][k] + arr[j - 1] * arr[l] * arr[k];
				
				if(q < m[j][k]){

					m[j][k] = q;
					s[j][k] = l;

				}

			}
		
		}

	}

	cout << m[1][n - 1] << endl;
	printOptimalParens((int*)s, 1, n - 1, n);
	cout << endl;

}

int main(){

	int size;
	cin >> size;

	int arr[size + 1];

	for(int i = 0; i <= size; i++){

		cin >> arr[i];

	}

	matrixChainOrder(arr, size + 1);

}
