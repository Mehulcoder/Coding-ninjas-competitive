/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
AIRPORTS
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

bool mysort(pii a, pii b){
	return (a.second<b.second);
}

void create(vector<pii>* graph, vector<int> &component, int* visited, int start, int a, int &total_cost){
	//cout << "Start "<<start << '\n';
	visited[start] = 1;
	cout<<total_cost<<endl;	
	for (int i = 0; i < graph[start].size(); ++i)
	{
		int next = graph[start].at(i).first;
		if (visited[next] == 0)
		{
			if (a<=graph[start].at(i).second)
			{
				continue;
			}else{
				component.push_back(next);
				total_cost = total_cost + graph[start].at(i).second;
				//cout << "Next "<<next << '\n';
				create(graph, component, visited, next, a, total_cost);
			}
		}
	}

	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;
	int l = 0;
	while(t--){
		l++;
		int n, m, a, total_cost, total_airports;
		total_cost = 0;
		total_airports = 0;
		cin>>n>>m>>a;

		vector<pii>* graph = new vector<pii>[n];
		int* visited = new int[n];
		for (int i = 0; i < n; ++i)
		{
			visited[i] = 0;
		}

		while(m--){
			int x, y, c;
			cin>>x>>y>>c;
			graph[x-1].push_back({y-1, c});
			graph[y-1].push_back({x-1, c});
		}

		//Sorting the graph
		for (int i = 0; i < n; ++i)
		{
			sort(graph[i].begin(), graph[i].end(), mysort);
		}

		vector<vector<int>> components;
		//int check = 0;
		for (int i = 0; i < n; ++i)
		{
			if (visited[i] == 0)
			{
				
				vector<int> component;
				component.push_back(i);
				create(graph, component, visited, i, a, total_cost);
				components.push_back(component);
				
			}
		}

		total_airports = components.size();

		cout <<"Case #"<<l<<": "<<total_cost+total_airports*a<<" "<<total_airports << '\n';

		for (int i = 0; i < components.size(); ++i)
		{
			for (int j = 0; j < components[i].size(); ++j)
			{
				cout<<components[i][j]<<" ";
			}
			cout << '\n';
		}

		cout << "Total road cost = "<<total_cost << '\n';
	}


	return 0 ; 



}
