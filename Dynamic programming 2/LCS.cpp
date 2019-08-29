/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. 
Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
*/

#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2){

	int m = s1.size();
	int n = s2.size();

	vector<vector<int>> dp(m, vector<int> (n,0));

	if (s1[0] == s2[0])
	{
		dp[0][0] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		if(s1[0] == s2[i])
			dp[0][i] = 1;
		else
			dp[0][i] = dp[0][i-1];
	}

	for (int i = 1; i < m; ++i)
	{
		if(s1[i] == s2[0])
			dp[i][0] = 1;
		else
			dp[i][0] = dp[i-1][0];
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if(s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << dp[i][j]<<" " ;
	// 	}
	// 	cout <<'\n';
	// }


	return dp[m-1][n-1];


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string s1, s2;
	cin>>s1>>s2;

	cout << lcs(s1, s2) << '\n';

	return 0 ; 



}
