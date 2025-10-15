#include<bits/stdc++.h>
using namespace std;

int main(){
    int numofvertices=0;
    cout << "Enter no of vertices u want";
    cin >> numofvertices;
    vector<vector<int>> graph(numofvertices,vector<int>(numofvertices,0));
    int row=-1;
    int col=-1;
    int loop = 1;
    while(loop)
    {
        cout << "Enter Vertice No connection from (0 , number -1)" ;
        cin >> row;
        cout << "Enter vertex no Connection to (0,num-1) ";
        cin >> col;
        graph[row][col] = 1;
        cout << "press 0 to exit any other number to exit";
        cin >> loop;
    }
    cout << "graph as of now" << endl;
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[0].size();j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}