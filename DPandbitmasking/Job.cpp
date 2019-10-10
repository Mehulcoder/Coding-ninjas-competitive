/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007


int mincost(int cost[4][4], int n, int p, int mask, int* dp){

	if (p>=n)
	{
		return 0;
	}

	if (dp[mask]!=INT_MAX)
	{
		return dp[mask];
	}
	
	int minimum = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (!(mask&(1<<i)))
		{
			int ans = mincost(cost, n, p+1, mask|(1<<i)) + cost[p][i];
			minimum = min(ans, minimum);
		}
	}

	dp[mask] = minimum
	return minimum;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int* dp = new dp[1<<4];
	for (int i = 0; i < (1<<4); ++i)
	{
		dp[i] = INT_MAX;
	}
	//dp[0] = 0;

	int cost[N][N] = 
	{ 
        {9, 2, 7, 8}, 
        {6, 4, 3, 7}, 
        {5, 8, 1, 8}, 
        {7, 6, 9, 4} 
    };

    cout << mincost(cost, 4, 0, 0, dp) << '\n';


	return 0 ; 



}
