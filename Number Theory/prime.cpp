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


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	int count = 0;

	if (n>=2)
	{
		count++;
	}
	if (n>=3)
	{
		count++;
	}

	//cout << n << '\n';
	for (int i = 2; i <= n; ++i)
	{
		int flag = 0;
		for (int j = 2; j*j <= i; ++j)
		{
			if (i%j==0)
			{
				flag = 0;
				break;
			}else{
				flag = 1;
			}

		}
		if (flag == 1)
		{
			count++;
		}
	}

	cout <<count<<endl;	



	return 0 ; 



}

