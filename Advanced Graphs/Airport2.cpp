/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
Case #1: 145 1
Case #2: 2090 2

*/

#include <bits/stdc++.h>
using namespace std;

class Edges{
  
    public:
    
    int src;
    int dest;
    int weight;
    
};

class compare{
    public:
    bool operator()(Edges const &a,Edges const &b){
        return a.weight<b.weight;
    }
};
    
    

int findParent(int *parent ,int vertex){
    
    if(parent[vertex]==vertex)
        return vertex;
    
    return findParent(parent,parent[vertex]);
    
}

int getOutput(Edges *input,int size,int *parent,int V,int A,int *count){
        
    int totalweight=0;
    
        for(int i=0;i<size;i++){
            Edges e = input[i];
            
            int p1 = findParent(parent,e.src);
            int p2 = findParent(parent,e.dest);
            
            if(p1!=p2 && e.weight<A){
                totalweight += e.weight;
                parent[p1] = p2;
            }
            
            
        }
        
     
    
        for(int i=1;i<=V;i++){
            
            if(parent[i]==i)
                (*count)++;
            
            
        }
        
    totalweight+=((*count)*A);
    
    return totalweight;
    
}

int main()
{
  int t;
  cin>>t;
  int c=1;  
  while(t--){  
  int V,E,A;
  cin>>V>>E>>A;
    
    Edges *input = new Edges[E];
    
    for(int i=0;i<E;i++){
        Edges e;
        cin>>e.src>>e.dest>>e.weight;
        input[i] = e;
    }
    
    sort(input,input+E,compare());
    
    int count =0;
    
    int *parent = new int[V+1];
    
    for(int i=0;i<=V;i++){
        parent[i] = i;
    }
    int output = getOutput(input,E,parent,V,A,&count);
    
    cout<<"Case #"<<c<<": "<<output<<" "<<count<<endl;   
    c++;      
    
  }

  return 0;
}