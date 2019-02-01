#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visit[101] = {false};
vector<int> adj[101];
vector<int> rev[101];
vector<int> order;
vector<vector<int>> SCC;

void DFS(vector<int> graph[], vector<int> &res, int n){

	visit[n] = true;

	for(int i = 0; i < graph[n].size(); i++){

		if(!visit[graph[n][i]]){

			DFS(graph, res, graph[n][i]);

		}

	res.push_back(n);

	}

}

int main(){

	int vert = 0;
	int edge = 0;

	cin >> vert >> edge;

	int arr[vert];

	for(int i = 0; i < vert; i++){

		arr[i] = i;

	}

	int temp1;
	int temp2;

	for(int i = 0; i < edge; i++){

		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);

	}


	for(int i = 0; i < vert; i++){

		if(!visit[i]){

			DFS(adj, order, i);

		}

	}

	for(int i = 0; i < vert; i++){

		for(int j = 0; j < adj[i].size(); j++){

			rev[adj[i][j]].push_back(i);

		}

	}

	for(int i = 0; i < vert; i++){

		visit[i] = false;

	}

	reverse(order.begin(), order.end());

	for(int i = 0; i < order.size(); i++){

		if(!visit[order[i]]){

			vector<int> compon;
			DFS(rev, compon, order[i]);
			SCC.push_back(compon);

		}

	}

	for(int i = 0; i < SCC.size(); i++){

		for(int j = 0; j < SCC[i].size(); j++){

			int compare = SCC[i][j];
			for(int k = 0; k < vert; k++){

				if(arr[k] == compare){

					arr[k] = *min_element(SCC[i].begin(), SCC[i].end());

				}

			}

		}

	}

	for(int i = 0; i < vert; i++){

		cout << arr[i] << endl;

	}

}


