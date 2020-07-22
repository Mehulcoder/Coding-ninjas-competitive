bool check(char graph[][MAXN],int n,int m,bool visited[][MAXN],string s,int i,int j)
{
    if(s[0]=='\0')
        return true;
    if(visited[i][j]==true)
        return false;
    visited[i][j]=true;
    bool ans=false;
	if(graph[i-1][j-1]==s[0]&&(i-1>=0&&j-1>=0))
    {
       ans=check(graph,n,m,visited,s.substr(1),i-1,j-1);
        if(ans)
            return true;
    }
    if(graph[i-1][j]==s[0]&&i-1>=0)
    {    ans=check(graph,n,m,visited,s.substr(1),i-1,j);
     if(ans)
            return true;
    }
    if(graph[i-1][j+1]==s[0]&&(i-1>=0&&j+1<m))
    {   ans = check(graph,n,m,visited,s.substr(1),i-1,j+1);
     if(ans)
            return true;
    }
    if(graph[i][j+1]==s[0] && j+1<m)
    {	ans = check(graph,n,m,visited,s.substr(1),i,j+1);
     if(ans)
            return true;
    }
     if(graph[i+1][j+1]==s[0] && (j+1<m&&i+1<n))
     {
         ans = check(graph,n,m,visited,s.substr(1),i+1,j+1);
         if(ans)
            return true;
     }
     if(graph[i+1][j]==s[0] && i+1<n)
     {ans= check(graph,n,m,visited,s.substr(1),i+1,j);
      if(ans)
            return true;
     }
     if(graph[i+1][j-1]==s[0] && (j-1>=0&&i+1<n))
     {ans = check(graph,n,m,visited,s.substr(1),i+1,j-1);
      if(ans)
            return true;
     }
     if(graph[i][j-1]==s[0] && j-1>=0)
     {ans = check(graph,n,m,visited,s.substr(1),i,j-1);
       if(ans)
            return true;
     }
    visited[i][j]=false;
	if(ans==false)
        return false;
    
    
}
int solve(char graph[][MAXN],int N, int M)
{
	// Write your code here.
    bool visited[N][MAXN]={false};
    string s="CODINGNINJA";
    for(int k=0;k<N;k++)
    {
        for(int l=0;l<M;l++)
        {	if(graph[k][l]=='C')
        	{
            if(check(graph,N,M,visited,s.substr(1),k,l))
                return true;
        	}
        }
        
