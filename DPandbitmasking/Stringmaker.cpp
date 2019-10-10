/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :
Line 1 : String A
Line 2 : String B
Line 3 : String C
Output Format :
The number of ways to form string C
Constralls :
1 <= |A|, |B|, |C| <= 50
Sample Input :
abc
abc 
abc
Sample Output :
8
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
ll dp[100][100][100];

int memsolver(string a,string b,string c){
	ll x = a.size();
	ll y = b.size();
	ll z = c.size();

	ll ans = 0;
	
	if (z == 0)
	{
	 	return 1;
	}

	if (x<=0 && y<=0)
	{
		return 0;
	}

	if (dp[x][y][z]!=-1)
	{
		return dp[x][y][z];
	}

	for (ll i = 0; i < a.size(); ++i)
	{
		if (a[i]==c[0])
		{
			ans+=memsolver(a.substr(i+1), b, c.substr(1));
		}
	}

	

	for (ll i = 0; i < b.size(); ++i)
	{
		if (b[i] == c[0])
		{
			ans+=memsolver(a, b.substr(i+1), c.substr(1));
		}
	}

	dp[x][y][z] = ans%MOD;
	return ans%MOD;
}

int solve(string a,string b,string c)
{
	memset(dp, -1, sizeof(dp));
	return memsolver(a, b, c);	
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	string a,b,c;
	cin>>a>>b>>c;

	cout<<solve(a,b,c)<<endl;

	return 0 ; 
}
