#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> graph, int i)
{
    cout << "BFS:" << endl;
    int visited[graph.size() - 1]{0};
    queue<int> q;
    visited[i] = 1;
    cout << i << endl;
    q.push(i);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int j = 0; j <= graph.size(); j++)
        {
            if (graph[k][j] == 1 && visited[j] == 0)
            {
                cout << j << endl;
                visited[j] = 1;
                q.push(j);
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
            if(graph[i][j]==1 && visited[j]==0)
                dfs(graph, j);
        }
    }
}
/*BFS CODE WORKS PROPERLY I DONT HAVE PATEINCE TO MAKE DFS CODE RUN I WILL UPDATE IT SHORTLY*/
int main()
{
    int numofvertices = 0;
    vector<vector<int>> graph(numofvertices, vector<int>(numofvertices, 0));
    cout << "Enter no of vertices u want";
    cin >> numofvertices;
    int row = -1;
    int col = -1;
    int loop = 1;
    while (loop)
    {
        cout << "Enter Vertice No connection from (0 , number -1)";
        cin >> row;
        cout << "Enter vertex no Connection to (0,num-1) ";
        cin >> col;
        graph[row][col] = 1;
        cout << "press 0 to exit any other number to exit";
        cin >> loop;
    }
    cout << "graph as of now" << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    int bfsexp;
    cout << "Enter the node where you want to start ur bfs from: " << endl;
    cin >> bfsexp;
    bfs(graph, bfsexp);
    return 0;
}