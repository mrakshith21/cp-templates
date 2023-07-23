#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> tin, tout;
vector<int> euler;

int t = 0;

// dfs to build the euler tour of a tree
void dfs(int i, int p){
    euler.emplace_back(i);
    tin[i] = t++;
    for(int j : adj[i]){
        if(j != p){
            dfs(j, i);
        }
    }
    tout[i] = t;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

