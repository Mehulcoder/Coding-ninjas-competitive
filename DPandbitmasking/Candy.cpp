/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
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
#define MAXN 16

int go(int like[][MAXN], int n, int student, int mask, int* dp){

	int ans = 0;

	if (student>=n)
	{
		return 1;
	}

	if (dp[mask]!=-1)
	{
		return dp[mask];
	}

	for (int i = 0; i < n; ++i)
	{
		if (!(mask&(1<<i)) && (like[student][i] == 1))
		{
			//cout << "i: "<<i<<" mask: "<<mask << '\n';
			ans = ans+go(like, n, student+1, mask|(1<<i), dp);
		}
	}

	dp[mask] = ans;
	return ans;
}

long long solve(int like[][MAXN],int N)
{
	int* dp = new int[1<<N];
	for (int i = 0; i < (1<<N); ++i)
	{
		dp[i] = -1;
	}
	return go(like,N, 0, 0, dp);
}
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;

	return 0 ;

}
