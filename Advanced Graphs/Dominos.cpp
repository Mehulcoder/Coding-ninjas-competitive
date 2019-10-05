/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<int>* graph, int start, bool* visited, stack<int> &s){
	visited[start] = 1;

	for (int i = 0; i < graph[start].size(); ++i)
	{
		if (visited[graph[start].at(i)] == 0)
		{
			dfs1(graph, graph[start].at(i), visited, s);			
		}	
	}

	//Will put in stack in the last
	s.push(start);

	return;
}

void dfs2(vector<int>* graph, int start, bool* visited){
	visited[start] = 1;
	for (int i = 0; i < graph[start].size(); ++i)
	{
		int v = graph[start].at(i);
		if (visited[graph[start].at(i)] == 0)
		{
			dfs2(graph, v, visited);
		}
	}

	return;
}

void kosaraju(vector<int>* graph, vector<int>* grapht, int n){
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	stack<int> s;

	for (int i = 0; i < n; ++i)
	{
		if (visited[i]==0)
		{
			dfs1(graph, i, visited, s);
		}
	}

	//Step 2
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		if (visited[v] == 0)
		{
			count++;
			dfs2(graph, v, visited);
		}
	}

	cout << count << '\n';


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;

		vector<int>* graph = new vector<int>[n];
		vector<int>* grapht = new vector<int>[n];
		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin>>u>>v;
			graph[u-1].push_back(v-1);
			grapht[v-1].push_back(u-1);
		}

		kosaraju(graph, grapht, n);

	}


	return 0 ; 



}
