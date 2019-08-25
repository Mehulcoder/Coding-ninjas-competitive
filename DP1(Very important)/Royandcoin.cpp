/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4

*/

#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, m;
	cin>>n>>m;
	vector<int> s(n+1, 0);
	vector<int> e(n+1, 0);

	vector<int> buffer(n+1, 0);


	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin>>a>>b;

		s[a]++;
		e[b]++;
	}

	for (int i = 1; i < n+1; ++i)
	{
		buffer[i] = s[i] - e[i-1] + buffer[i-1];
	}

	//Will store ki i coins kitne boxes me hai
	vector<int> coins(n+1,0);
	for (int i = 1; i < n+1; ++i)
	{
	 	coins[buffer[i]]++;
	}

	for (int i = n-1; i >= 0; --i)
	{
		coins[i] += coins[i+1];
	}

	int q;
	cin>>q;

	for (int i = 0; i < q; ++i)
	{
		int temp;
		cin>>temp;
		cout << coins[temp] << '\n';
	}



	return 0 ; 



}
