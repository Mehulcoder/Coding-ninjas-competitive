/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

#include <bits/stdc++.h>

using namespace std;

int lef(int** arr, int m, int n){
	int ans = 0;
	for (int i = n-1; i >= 0; --i)
	{
		if (arr[m][i] != 0)
		{
			return ans;
		}

		if (arr[m][i] == 0)
		{
			ans++;
		}
	}

	return ans;

}

int up(int** arr, int m, int n){
	int ans = 0;
	for (int i = m-1; i >= 0; --i)
	{
		if (arr[i][n] != 0)
		{
			return ans;
		}

		if (arr[i][n] == 0)
		{
			ans++;
		}
	}

	return ans;

}


int findMaxSquareWithAllZeros(int** arr, int m, int n){
    
    vector<vector<int>> dp(m, (vector<int>(n, 0)));

    for (int i = 0; i < n; ++i)
    {
    	if (arr[0][i] == 0)
    	{
    		dp[0][i] = 1;
    	}else{
    		dp[0][i] = 0;
    	}
    }

    for (int j = 0; j < m; ++j)
    {
    	dp[j][0] = (arr[j][0] == 0);
    }

    for (int i = 1; i < m; ++i)
    {
    	for (int j = 1; j < n; ++j)
    	{
    		if (arr[i][j] == 0)
    		{
    			int dig = dp[i-1][j-1];
	    		int upper = up(arr, i, j);
	    		int left = lef(arr, i, j);
	    		int z = min(dig, min(upper, left));
	    		dp[i][j] = z+1;

    		}else{
    			dp[i][j] = 0;
    		}
    		
    	}
    }

    int max = 0;
    for (int i = 0; i < m; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		max = std::max(max, dp[i][j]);
    	}
    }

    return max;
    
    
}
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	



	return 0 ; 



}
