#include <iostream>
#include <vector>
#include <limits> // Required for numeric_limits
#include<queue>
// It's generally better to use specific headers than <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> graph,int i)
{
    queue<int> q;
    int visited[graph.size()-1]{0};
    cout << "BFS:" << endl;
    cout << i << endl;
    visited[i]=1;
    q.push(i);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        for(auto x: graph[k])
        {
            if(visited[x]==0)
            {
                cout << x << endl;
                q.push(x);
                visited[x]=1;
            }
        }
    }
}

//int visited[graph.size() - 1]{0};
void dfs(vector<vector<int>> graph, int i)
{
    int visited[graph.size() - 1]{0};
    if (visited[i] == 0)
    {
        cout << i << endl;
        visited[i] = 1;
        for (int j = 0; i < graph[i].size(); j++)
        {
            dfs(graph, j);
        }
    }
}

/*BFS CODE WORKS PROPERLY I DONT HAVE PATEINCE TO MAKE DFS CODE RUN I WILL UPDATE IT SHORTLY*/

int main() {
    int numVertices;
    cout << "Enter the total number of vertices in the graph: ";
    cin >> numVertices;

    // --- KEY FIX ---
    // Initialize the graph with 'numVertices' empty vectors.
    // This is the most important change.
    vector<vector<int>> graph(numVertices);

    int loop = 1;
    int u, v;

    while (loop) {
        cout << "\n----------------------------------------" << endl;
        cout << "Enter 0 to stop adding edges, or 1 to continue: ";
        cin >> loop;

        if (!loop) {
            break;
        }

        cout << "Enter the edge (from one vertex to another):" << endl;
        cout << "Enter first vertex u: ";
        cin >> u;
        cout << "Enter second vertex v: ";
        cin >> v;

        // --- GOOD PRACTICE ---
        // Add a check to make sure the vertices are valid.
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) {
            cout << "Invalid vertex number! Please enter vertices between 0 and " << numVertices - 1 << "." << endl;
            continue; // Skip the rest of this loop iteration
        }

        // Now this is safe because graph[u] and graph[v] exist.
        graph[u].push_back(v);
        graph[v].push_back(u); // For an undirected graph
        
        cout << "Edge added between " << u << " and " << v << endl;
    }

    cout << "\n--- Final Adjacency List ---" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "Vertex " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " "; // Improved printing format
        }
        cout << endl;
    }
    bfs(graph,1);
    return 0;
}