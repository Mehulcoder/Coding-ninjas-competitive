/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3

*/

#include <bits/stdc++.h>

using namespace std;

int solve(string s1,string s2)
{
	int m =s1.size();
	int n =s2.size();

	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for (int i = 0; i < n+1; ++i)
	{
		dp[m][i] = n-i;
	}

	for (int i = 0; i < m+1; ++i)
	{
		dp[i][n] = m-i;
	}

	for (int i = m-1; i >= 0; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			int k = j;
			
			while(k<s2.size())
			{
				if(s2[k]==s1[i])
				{
					break;
				}
				k++;
			}
			if (k==s2.size())
			{
				dp[i][j] = 1;
				//return 1;
			}

			int c1 = 1+dp[i+1][k+1];
			int c2 = dp[i+1][j];

			dp[i][j] = min(c1, c2);
		}
	}

	return dp[0][0];


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;



	return 0 ; 



}
