#include <bits/stdc++.h>
using namespace std;
int start , des;
bool ch = false;
int q = 1;
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{

    visited[s] = true;
    
    res.push_back(s);
    
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
    if(s == des)
    {
        ch = true;
        return;
    } 
    res.pop_back();
}

vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, start, res);
    return res;
}

void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int n,m;
    cin >> n>>m;
    vector<vector<int>> adj(n+1);

    vector<vector<int>> edges;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    
    cin >>start >> des;
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);
    vector<int> res = DFS(adj); 
    if(ch)
    {
        for(int i = 0; i < q;i++)
        {
            int chy = res[i];
            cout << res[i];
            if(chy != des){
                q++;
                cout << '>';
            }else{
                return 0;
            }  
        }
    }else{
        cout << "xxx";
    }
    cout << '\n';
    
}