#include <bits/stdc++.h>

using namespace std;

/* 
    find path from a to b in a graph, assuming the path exists
*/

vector<int> get_path(int a, int b, vector<vector<int>>& adj, int n){
    vector<int> parent(n);
    queue<int> q;
    vector<bool> visited(n);
    visited[a] = true;
    q.push(a);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y: adj[x]){
            if(!visited[y]){
                parent[y] = x;
                q.push(y);
                visited[y] = true;
            }
        }
    }
    vector<int> path;
    int v = b;
    while(v != a){
        path.emplace_back(v);
        v = parent[v];
    }
    path.emplace_back(a);
    reverse(path.begin(), path.end());
    return path;
}

