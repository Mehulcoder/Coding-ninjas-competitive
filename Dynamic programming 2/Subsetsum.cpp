/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
YES
*/

#include <bits/stdc++.h>

using namespace std;

void go(vector<int> arr, int n, int i , int sum){
	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i < sum+1; ++i)
	{
		dp[n][i] = 0;
	}

	for (int j = 1; j < sum+1; ++j)
	{
		for (int i = n-1; i >= 0; --i)
		{
			bool c1 = 0;
			if (j-arr[i]>=0)
			{
				c1 = dp[i+1][j-arr[i]];	
			}

			if (c1 == 1)
				dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i+1][j];

			}
		}
	}

	// for (int i = 0; i < n+1; ++i)
	// {
	// 	for (int j = 0; j < sum+1; ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout <<'\n';
	// }

	if (dp[0][sum] == 1)
	{
		cout << "Yes" << '\n';
	}else
		cout << "No" << '\n';

	return;



}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL); 
	
	int n;
	cin>>n;

	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int sum;
	cin>>sum;

	go(arr, n, 0, sum);



	return 0 ; 



}
