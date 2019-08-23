/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
				PROBLEM STATEMENT
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> v){
	int n = v.size();
	int maxtillnow = 0;
	int maxendinghere = 0;


	for (int i = 0; i < n; ++i)
	{
		if (maxendinghere+v[i]<v[i])
		{
			maxendinghere = v[i];
		}else{
			maxendinghere += v[i];
		}

		if (maxendinghere>maxtillnow)
		{
			maxtillnow = maxendinghere;
		}

		
	}

	return maxtillnow;



}

int go(vector<vector<int>> arr, int m, int n){

	int ans = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		std::vector<int> sum(m, 0);

		for (int j = i; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				sum[k] += arr[k][j];
			}

			int temp = kadane(sum);
			ans = max(ans, temp);
		}
	}

	return ans;

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int m, n;
	cin>>m>>n;

	vector<vector<int>> matrix(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>matrix[i][j];
		}
	}

	cout <<  go(matrix, m, n) <<endl;


	return 0 ; 



}
