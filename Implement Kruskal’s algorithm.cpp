#include <iostream>
using namespace std;

#define MAX 100
#define INF 999999

int main()
{
    int n;
    int cost[MAX][MAX];
    int parent[MAX];
    int minCost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n >= MAX)
    {
        cout << "Invalid number of vertices!";
        return 0;
    }

    cout << "Enter cost adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (i == j)
                cost[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edges = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = INF;
        int u = -1, v = -1;

        // Find minimum-weight edge
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (u == -1 || min == INF)
        {
            cout << "Graph is disconnected. MST cannot be formed.\n";
            return 0;
        }

        int a = u;
        int b = v;

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b)
        {
            cout << u << " - " << v << " : " << min << endl;

            minCost += min;
            parent[a] = b;
            edges++;
        }

        cost[u][v] = INF;
        cost[v][u] = INF;
    }

    cout << "Total cost of MST: " << minCost << endl;

    return 0;
}
