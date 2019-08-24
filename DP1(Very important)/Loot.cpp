/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110

*/

#include <bits/stdc++.h>

using namespace std;

int getMaxMoney(int arr[], int n){
	std::vector<int> dp(n, 0);

	if (n==1)
	{
		return arr[0];
	}
	if (n==2)
	{
		return max(arr[0], arr[1]);
	}

	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0]);

	for (int i = 2; i < n; ++i)
	{
		dp[i] =max(dp[i-1], arr[i] + dp[i-2]);
	}

	return *max_element(dp.begin(), dp.end());

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);



	return 0 ; 



}
