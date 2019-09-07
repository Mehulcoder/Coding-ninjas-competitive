/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include <bits/stdc++.h>

using namespace std;

int go(vector<int> v, char x, int a, int b){


	
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, q;
	cin>>n>>q;
	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	for (int i = 0; i < q; ++i)
	{
		char x;
		int a;
		int b;
		cin>>x>>a>>b;
		cout << go(v, x, a, b) << '\n';

	}

	return 0 ;
}
