#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
typedef long long int LL;
typedef pair<int, int > pii;
const int MAXN = 2001;
LL P[11] = {1,2,3,5,7,11,13,17,19,23,29};
LL dp[2][MAXN][MAXN];
int profit[MAXN];
int weight[MAXN];
vector<pii > v;
int main() {
	int N,W;
	scanf("%d%d",&N,&W);
	assert(N >= 1 && N <= 2000);
	assert(W >= 1 && W <= 2000);
	rep(i,1,N+1) {
		scanf("%d%d",&profit[i], &weight[i]);
		assert(profit[i] >= 1 && profit[i] <= 1000000000);
		assert(weight[i] >= 1 && weight[i] <= 2000);
		v.push_back(make_pair(profit[i], weight[i]));
	}
	sort(v.begin(), v.end());
	rep(i,1,N+1) {
		profit[i] = v[i-1].first;
		weight[i] = v[i-1].second;
	}
	rep(p,0,11) rep(i,1,N+1) rep(j,1,W+1) {
		if(!p) {
			dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]);
			if(j >= weight[i])
				dp[0][i][j] = max(dp[0][i][j], dp[0][i-1][j-weight[i]]+profit[i]);
		} else {
			int cur = p&1;
			int prev = 1-cur;
			dp[cur][i][j] = dp[prev][i][j];
			dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i-1][j]);
			dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i][j-1]);
			if(j >= weight[i]) {
				dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i-1][j-weight[i]]+profit[i]);
				dp[cur][i][j] = max(dp[cur][i][j], dp[prev][i-1][j-weight[i]]+P[p]*profit[i]);
			}
		}
	}
	cout << dp[0][N][W] << endl;
	return 0;
}