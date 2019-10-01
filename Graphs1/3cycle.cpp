int helper(int i, int** matrix, int n, int* visited, int & count){
    for(int j=1;j<n+1;j++){
        if(visited[j]==0 && matrix[i][j]==1){
            for(int k=1;k<n+1;k++){
                if(visited[k]==0 && matrix[j][k]==1 && matrix[k][i]==1){
                count++;
           //     cout<<"i-"<<i<<endl;
             //   cout<<"j-"<<j<<endl;
              //  cout<<"k-"<<k<<endl;
                
                //cout<<"Count-"<<count<<endl;
                }
            }
        }
   
    }
   //  cout<<"Count2-"<<count<<endl;
     return count/2;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
    //Creating matrix
    int** matrix = new int*[n+1];
    
    for(int i=0;i<=n;i++){
        matrix[i] = new int[n+1];
        
        for(int j=0;j<=n;j++){
            matrix[i][j]=0;
        }
        
    }
    
    for(int i=0;i<m;i++){
        matrix[u.at(i)][v.at(i)]=1;
        matrix[v.at(i)][u.at(i)]=1;
       // cout<<"U-"<<u[i]<<endl;
       // cout<<"V-"<<v[i]<<endl;
        
        
    }
    //Make visisted matrix
    int* visited = new int[n+1];
    
    for(int i=0;i<n+1;i++){
        visited[i] = 0;
    }
    
    //Look for cycle in each element
    int sum=0;
    for(int i = 1; i<=n; i++){
        visited[i]=1;
        int count=0;
        sum=sum+helper(i,matrix, n,visited, count);
    }
    
    return sum;
}