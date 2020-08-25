/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : Take graph input in adjacency matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Note : 1. Take graph input in the adjacency matrix.
       2. Handle for Disconnected Graphs as well
Input Format :
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/



/*
					Contributer: Bhavya Tyagi
					Thapar Institute of Engineering & Technology, Patiala
					Added The Modified code after the question includes Disconnected Graphs too
*/

#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges,int n, int j,bool *visited)
{
	
	queue <int> q;
	q.push(j);
	visited[j]=true;
	while(!q.empty())
	{
		int currentEdge=q.front();
		cout<<currentEdge<<" ";
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(i==currentEdge)
			continue;
			if(edges[currentEdge][i]&&!visited[i])
			{
				q.push(i);
				visited[i]=true;
			}
			
		}
	}
}

void BFS(int **edges,int n)
{
	bool *visited=new bool [n];
	
	for(int i=0;i<n;i++)
	visited[i]=false;
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		printBFS(edges,n,i,visited);
	}
	delete[]visited;
}

int main()
{
    int n,e;
    cin>>n>>e;
    
    int **edges=new int*[n];
    
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        edges[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited=new bool[n];
    
    for(int i=0;i<n;i++)
    visited[i]=false;
    

	BFS(edges,n);

    
    return 0;
}




/*

			Old code without Disconnected Graphs (Only 50% Testcase Passes with the old code)
			by Mehul Chaturvedi
*/

#include <bits/stdc++.h>

using namespace std;


void print(int** edges, int n, int* visited, int sv){
	//cout << sv << '\n';
	visited[sv] = 1;

	queue<int> temp;
	temp.push(sv);
	while(!temp.empty()){
		int top = temp.front();
		temp.pop();
		cout << top << " ";
		//visited[temp] = 1;

		for (int i = 0; i < n; ++i)
		{
			if (i==top)
			{
				continue;
			}
			if (edges[top][i] == 1 && visited[i] == 0)
			{
				temp.push(i);		
				visited[i] = 1;
			}
		}
	}

	return;
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

		

	print(edges, n, visited, 0);




	return 0 ; 



}
