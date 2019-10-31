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

// S and T - input strings
// You need to check if string T is present in S or not

int findString(char S[], char T[]) {
	int length = strlen(T);
	int n = strlen(S);


	vector<int> pitable(length, 0);
	int i = 0;
	int j = i+1;

	while(j<length && i<length){
		if (T[i]==T[j])
		{
			pitable[j] = i+1;
			i++;
			j++;
		}else
		{
			if (i!=0)
			{
				i = pitable[i-1];

			}
			j++;
		}
	}

	// for (int k = 0; k < length; ++k)
	// {
	// 	cout << pitable[k] << ' ';
	// }
	// cout <<  '\n';
	// return 0;

	int p = 0;
	int q = 0;
	while(q<length && p<n){
		if (S[p] == T[q])
		{
			p++;
			q++;
		}else
		{
			//cout << "here" << '\n';
			if (q==0)
			{
				p++;
				continue;
			}
			q = pitable[q-1];
		}
	}

	if (q==length)
	{
		return p-length;
	}


	return -1;

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	

	char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout<<findString(S, T)<<endl;	



	return 0 ; 



}

