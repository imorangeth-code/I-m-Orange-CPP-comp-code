#include <bits/stdc++.h>
using namespace std;
int start , des;
bool ch = false;
int q = 1;
// Code Inspired By GeeksforGeeks
void bfs(vector<vector<int> >& graph, int S, vector<int>& par, vector<int>& dist)
{
    queue<int> q;
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbour : graph[node]) {
            if (dist[neighbour] == 1e9) {
                par[neighbour] = node;
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }
}

void printShortestDistance(vector<vector<int> >& graph, int S, int D, int V)
{
    vector<int> par(V, -1);
    vector<int> dist(V, 1e9);
    bfs(graph, S, par, dist);
    if (dist[D] == 1e9) {
        cout << "xxx";
        return;
    }
    vector<int> path;
    int currentNode = D;
    path.push_back(D);
    while (par[currentNode] != -1) {
        path.push_back(par[currentNode]);
        currentNode = par[currentNode];
    }
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i]+1;
        if(i !=0)cout << '>';
    }
        
}

int main()
{
    int V , E ;
    cin >> V >> E;
    int S, D;
    vector<vector<int>> edges;
    while(E--)
    {
        int a,b;
        cin >> a >> b;
        edges.push_back({a-1,b-1});
    }
    cin >>S >> D;
    vector<vector<int> > graph(V);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    printShortestDistance(graph, S-1, D-1, V);
    return 0;
}

/*
5
6
1 2
1 3
2 4
3 4
4 5
2 5
1
5
*/