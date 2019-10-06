/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shaint have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases fointow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

using namespace std;
#define pencho ios_base::sync_with_stdio(0);cin.tie(0); 
#define mod 1000000007
int n;
int dp[10001];
int solve(vector<int>adj[])
{
    queue<int>q;
    dp[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int idx=q.front();
        q.pop();
        for(int i=0;i<adj[idx].size();i++)
        {
            if(dp[adj[idx][i]]==-1)
            {
                dp[adj[idx][i]]=dp[idx]+1;
                q.push(adj[idx][i]);
            }
        }
    }
    return dp[n];
}
int main()
{
    pencho
    int t,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        vector<int>adj[n+1];
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout<<solve(adj)<<endl;
    }
}