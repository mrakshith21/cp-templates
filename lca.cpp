#include <bits/stdc++.h>

using namespace std;
/*
    lca using binary lifting
    0 - indexed vertices
    source:https://cp-algorithms.com/graph/lca_binary_lifting.html
    
    remember to call build() after adding edges
*/
class lca{   

public:

    int n, l;
    vector<vector<int>> adj;

    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<int> depth;

    bool built = false;

    // private method
    void preprocess(int root) {
        assert(!built);
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root, 0);
    }

    void dfs(int v, int p, int d)
    {
        depth[v] = d;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, d + 1);
        }

        tout[v] = ++timer;
    }

    lca(int n){
        this->n = n;
        adj = vector<vector<int>>(n);
    }

    void add_edge(int a, int b){
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    void build(int root){
        assert(!built);
        preprocess(root);
        built = true;
    }
    
    bool is_ancestor(int u, int v)
    {
        assert(built);
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v)
    {
        assert(built);
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }    

    int distance(int a, int b){
        assert(built);
        assert(0 <= a and a < n);
        assert(0 <= b and b < n);
        int l = get_lca(a, b);
        int ans = depth[a] + depth[b] - 2 * depth[l];
        return ans;
    }
};


/* sample usage */
int main(int argc, char const *argv[])
{
    int n = 10;
    lca tree(n);
    for(int i = 0; i < n - 1; i++){
        tree.add_edge(i, i + 1);
    }
    tree.build(0);
    cout << tree.is_ancestor(5, 8);
    return 0;
}
