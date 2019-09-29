/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <iostream>


#include <bits/stdc++.h> 
using namespace std; 
void connected(bool** edges, int n, int sv, int *visited)
{
    int init=sv;
    
    while(init<n){
    if(visited[init]!=0){
        init++;
        continue;
    }
    visited[init] = 1;
    queue<int> q;
    q.push(init);
    init++;
        vector<int> v1;
    while(!q.empty())
    {
        int x = q.front();
        v1.push_back(x);
        
        q.pop();
        
        for(int i=0;i<n;i++)
        {
            if(edges[x][i] && !visited[i] )
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
        sort(v1.begin(), v1.end());
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    
    return;
   
}
int main()
{
    int V, E;
    cin >> V >> E;
    
    bool** edges = new bool*[V];
    for(int i=0; i<V; i++){
        edges[i]=new bool[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f;
        cin>>s;
        
        edges[f][s]=1;
        edges[s][f]=1;
        
        
    }

    int *visited = new int[V];
    for(int i=0;i<V;i++)
    	visited[i] = 0;
    
    connected(edges, V, 0 , visited);

  return 0;
}
