/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

#include <bits/stdc++.h>

using namespace std;
bool hasPath(int** edges, int n, int a, int b, int* visited){
	//Base Case
	if (a==b)
	{
		return 1;
	}
	int result = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (edges[a][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			result = hasPath(edges, n, i, b, visited);
			if (result==1)
			{
				return 1;
			}
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << visited[i] << ' ';
	// }

	return result;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, e;
	cin>>n>>e;

	int** edges = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}

	}

	int* visited = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin>>a>>b;

		edges[a][b] = 1;
		edges[b][a] = 1;
	}

	int c, d;
	cin>>c>>d;

	if(hasPath(edges, n, c, d, visited)){
		cout << "true" << '\n';
	}else{
		cout << "false" << '\n';
	}

	return 0 ; 



}
