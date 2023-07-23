#include <bits/stdc++.h>

using namespace std;

/* 
    find diameter of tree
*/

vector<int> dist(int a, vector<vector<int>>& adj, int n){
    queue<int> q;
    vector<int> d(n, -1);
    d[a] = 0;
    q.push(a);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y: adj[x]){
            if(d[y] == -1){
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    return d;
}

int max_index(vector<int>& arr){
    return max_element(arr.begin(), arr.end()) - arr.begin();
}

// CALL THIS METHOD
// returns the nodes which are the end points of the diamter
pair<int, int> diameter(vector<vector<int>>& adj, int n){
    vector<int> d1 = dist(0, adj, n);
    int b = max_index(d1);
    vector<int> d2 = dist(b, adj, n);
    int c = max_index(d2);
    return {b, c};
}
