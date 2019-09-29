#include <queue> 
#include <iostream> 
#include <unordered_map> 
using namespace std; 

vector<int>* getPath(int** edges, int n, int sv, int ev) 
{ 	queue<int> bfsQ; 
	bool * visited = new bool[n]; 
	for (int i = 0; i < n; i++) {
	 visited[i] = false;
	}

	bfsQ.push(sv);

	visited[sv] = true; 
	bool done = false; 
	unordered_map<int, int> parent; 
	while (!bfsQ.empty() && !done) { 
	 	int front = bfsQ.front(); 
	 	bfsQ.pop(); 
	 	for (int i = 0; i < n; i++) { 
	 		if (edges[front][i] && !visited[i]) { 
	 			parent[i] = front; bfsQ.push(i); 
	 			visited[i] = true; if (i == ev) { 
	 				done = true; 
	 				break; 
	 			} 
	 		} 
	 	} 
	} 
	delete [] visited; 
	if (!done) { 
		return NULL; 
	} else { 
	 	vector<int>* output = new vector<int>(); 
	 	int current = ev; 
	 	output->push_back(ev); 
	 	while (current != sv) { 
	 		current = parent[current]; 
	 		output->push_back(current); 
	 	} return output; 
	} 
	} 



	int main() { 
		int n; 
		int e; 
		cin >> n >> e; 
		int** edges = 
		new int*[n]; 
		for (int i = 0; i < n; i++) {
		 edges[i] = new int[n]; 
		 for (int j = 0; j < n; j++) { 
		 	edges[i][j] = 0; 
		 } 
		} for (int i = 0; i < e; i++) { 
			int f, s; 
			cin >> f >> s; 
			edges[f][s] = 1; edges[s][f] = 1; } 
			int sv, ev; 
			cin >> sv >> ev; 
			vector<int>* output = getPath(edges, n, sv, ev); 
			if (output != NULL) { 
				for (int i = 0; i < output->size(); i++) { 
					cout << output->at(i) << " "; 
				} delete output; 
			} for (int i = 0; i < n; i++) { 
				delete [] edges[i]; 
			} delete [] edges; 
		}