/*
Fill The Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define fill(a,x) memset(a,x,sizeof(a)) 
#define pb push_back
#define sz(x) (int)x.size() 
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
const ll INF = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+10; 

bool done[N];
int arr[N];
int grp[N];
vi edges[N];
vi zeros[N];
vector<ii> ones;

void dfsz(int s,int p,int g)
{
  done[s]=true;
  grp[s]=g;
  for(int i=0;i<sz(zeros[s]);i++)
  {
    if(zeros[s][i]==p or done[zeros[s][i]])
      continue;

    dfsz(zeros[s][i],s,g);
  }
}

bool dfs(int s,int p)
{
	done[s]=true;
	for(int i=0;i<sz(edges[s]);i++)
	{
		if(edges[s][i]==p)
			continue;

		if(arr[edges[s][i]]==arr[s])
			return false;

		if(done[edges[s][i]])
			continue;

		arr[edges[s][i]]=1-arr[s];
		bool check=dfs(edges[s][i],s);
		if(check==false)
			return false;
	}

	return true;
}
int main(){
  fast;
  int t;
  cin>>t;
  while(t--)
  {
    ones.clear();
  	int n,q;
  	cin>>n>>q;
  	FOR(i,1,n)
  	{
  		edges[i].clear();
      zeros[i].clear();
  		arr[i]=-1;
      grp[i]=0;
  		done[i]=false;
  	}

  	bool ans=true;
  	FOR(k,1,q)
  	{
  		int i,j,val;
  		cin>>i>>j>>val;
  		if(i==j and val==1)
  			ans=false;
      if(i==j and val==0)
        continue;
  		if(val==0)
  		{
        zeros[i].pb(j);
        zeros[j].pb(i);
      }
  		if(val==1)
  		ones.pb(make_pair(i,j));
  	}

  	if(ans==false)
  	{
  		cout<<"no"<<endl;
  		continue;
  	}

    int g=1;
    for(int i=1;i<=n;i++)
    {
      if(!done[i])
      {
        dfsz(i,0,g);
        g++;
      }
    }

    g--;
    FOR(i,0,sz(ones)-1)
    {
      if(grp[ones[i].F]==grp[ones[i].S])
        ans=false;
      else
        {
          edges[grp[ones[i].F]].pb(grp[ones[i].S]);
          edges[grp[ones[i].S]].pb(grp[ones[i].F]);
        }
    }

    if(ans==false)
    {
      cout<<"no"<<endl;
      continue;
    }

    for(int i=1;i<=g;i++)
      done[i]=false;

  	for(int i=1;i<=g;i++)
  	{
  		if(!done[i])
  		{
        arr[i]=0;
  			ans=dfs(i,0);
  			if(ans==false)
  			{
  				cout<<"no"<<endl;
  				break;
  			}
  		}
  	}

  	if(ans)
  	cout<<"yes"<<endl;
  }
  return 0;
}