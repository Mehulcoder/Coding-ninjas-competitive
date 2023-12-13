// Get Path DFS

#include <iostream>
#include <vector>
using namespace std;

vector<int> Get_Path(int **edges, int n, int s, int d, bool *visited)
{
    if (s == d)
    {
        vector<int> ans;
        visited[s] = true;
        ans.push_back(s);
        return ans;
    }

    visited[s] = true;

    for (int i = 0; i < n; ++i)
    {
        if (edges[s][i] == 1 && !visited[i])
        {
            vector<int> ans = Get_Path(edges, n, i, d, visited);

            if (!ans.empty())
            {
                ans.push_back(s);
                return ans;
            }
        }
    }

    return {};
}

int main()
{
    // KNOCKCAT \\

    int n, e;
    cout << "Enter number of vertices & edges : " << endl;
    cin >> n >> e;

    // for storing we need a 2d arary n*n;
    int **edges = new int *[n];

    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; ++i) // e edges
    {
        int f, s; // first vertex second vertes
        cout << "Enter edge from first vertex to second vertex" << endl;

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    int s, d;
    vector<int> ans;
    cout << "Enter source vertex & destination vertex for path " << endl;
    cin >> s >> d;

    ans = Get_Path(edges, n, s, d, visited);

    cout << "Path from " << s << " to " << d << endl;

    if (!ans.empty())
    {
        for (auto i : ans)
            cout << i << " ";
    }
    else
        cout << "No Path" << endl;

    // deleting memory
    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    delete[] visited;

    return 0;
}

/*

OUTPUT

PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Get_Path_DFS.cpp -o Get_Path_DFS } ; if ($?) { .\Get_Path_DFS }
Enter number of vertices & edges :
4 4
Enter edge from first vertex to second vertex
0 1
Enter edge from first vertex to second vertex
0 3
Enter edge from first vertex to second vertex
1 2
Enter edge from first vertex to second vertex
2 3
Enter source vertex & destination vertex for path
1 3
Path from 1 to 3
3 0 1
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ Get_Path_DFS.cpp -o Get_Path_DFS } ; if ($?) { .\Get_Path_DFS }
Enter number of vertices & edges :
6 3
Enter edge from first vertex to second vertex
5 3
Enter edge from first vertex to second vertex
0 1
Enter edge from first vertex to second vertex
3 4
Enter source vertex & destination vertex for path
0 3
Path from 0 to 3
No Path
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph>

*/
