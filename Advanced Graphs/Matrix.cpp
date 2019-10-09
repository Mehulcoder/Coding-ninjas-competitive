/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
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


/*

There can be a really easy greedy solution the problem.We can initialise the array A by -1.
There is crucial observation that the array A can be constructed with only two values 0 and 1.
Sort the index value pairs.Now if both the given index are unassigned,assign them according to 
the value given.Like 1 3 1 would mean 1 and 3 would be different .So initialise a[1] with 0 and 
a[3]=a[1]XOR val.Keep doing this and if at some point when both the indices are intialised with 
values!= -1 ,then check if they satisfy the given value,if not break and print -1.


1)I'll initialize an array of size n with -1
2)I'll then iterate over it and start with setting the first A[i] = 0 and then dfs will 
set the rest
3)Now in dfs i'll set the A[j](as already set A[i]) as A[i]^value if A[j]==-1
4)If it's not then it has to be equal to A[i]^value else return false

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
bool error; int col[N];
vector<pair<int,int> > adj[N];
void dfs(int start){
	for(auto edge: adj[start]){
		int next = edge.first;
		if(col[next] == -1){
			col[next] = col[start]^edge.second;
			dfs(next);
		} 
		else if(col[next] != col[start]^edge.second){
			error = true;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		error = false;
		for(int i=1;i<=n;i++){
			adj[i].clear();
			col[i] = -1;
		}
		while(m--){
			int a,b,c;
			cin>>a>>b>>c;
			adj[a].push_back({b,c});
			adj[b].push_back({a,c});
		}
		for(int i=1;i<=n;i++){
			if(col[i] == -1){
				col[i] = 0;
				dfs(i);
			}
		}
		if(error) cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}