// Return All Connected Connected_Components

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int **edges, bool *visited, int n, vector<int> &ans, int start)
{
    visited[start] = true;
    ans.push_back(start);

    for (int i = 0; i < n; ++i)
    {
        if (edges[start][i] == 1 && !visited[i])
            DFS(edges, visited, n, ans, i);
    }
}

void Connected_Components(int **edges, int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; ++i)
        visited[i] = false;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            // this vector creating againg and again
            vector<int> ans;

            DFS(edges, visited, n, ans, i);
            sort(ans.begin(), ans.end());

            for (int j = 0; j < ans.size(); ++j)
            {
                cout << ans[j] << " ";
            }
            cout << endl;
        }
    }
    delete[] visited;
}

int main()
{

    // KNOCKCAT \\

    int n;
    int e;

    cout << "Enter number of vertices & edges : " << endl;
    cin >> n >> e;

    // for storing we need to create a 2 d array n * n

    int **edges = new int *[n]; // dynamic array for storing edges

    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; ++i) // e edges
    {
        int f, s; // first vertex second vertex
        cout << "Enter edge from first vertex to second vertex " << endl;

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "Connected Components are " << endl;
    Connected_Components(edges, n);

    // deleting all the memory

    for (int i = 0; i < n; ++i)
        delete[] edges[i];

    delete[] edges;

    return 0;
}
