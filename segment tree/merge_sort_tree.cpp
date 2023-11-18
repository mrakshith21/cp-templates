#include <bits/stdc++.h>

using namespace std;

/*
    Credits: https://codeforces.com/blog/entry/122407, problem G
    Data structure that is used to handle queries of the form
    l r low high - count the number of elements between indices l to r
                   whose value lies between low and high

    **NOT TESTED by me**
*/

struct MergeSortTree {
    int n;
    vector<vector<int>> tree;
 
    void build(vector<int> &a, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = {a[l]};
            return;
        }
 
        int m = (l + r) / 2;
        build(a, 2 * x + 1, l, m);
        build(a, 2 * x + 2, m, r);
        merge(tree[2 * x + 1].begin(),
              tree[2 * x + 1].end(),
              tree[2 * x + 2].begin(),
              tree[2 * x + 2].end(),
              back_inserter(tree[x]));
    }
 
    MergeSortTree(vector<int>& a) : n(a.size()) {
        int SIZE = 1 << (__lg(n) + bool(__builtin_popcount(n) - 1));
        tree.resize(2 * SIZE);
        build(a, 0, 0, n);
    }
 
    int count(int lq, int rq, int mn, int mx, int x, int l, int r) {
        if (rq <= l || r <= lq) return 0;
        if (lq <= l && r <= rq) return lower_bound(tree[x].begin(), tree[x].end(), mx) - lower_bound(tree[x].begin(), tree[x].end(), mn);
 
        int m = (l + r) / 2;
        int a = count(lq, rq, mn, mx, 2 * x + 1, l, m);
        int b = count(lq, rq, mn, mx, 2 * x + 2, m, r);
        return a + b;
    }
 
    int count(int lq, int rq, int mn, int mx) {
        return count(lq, rq, mn, mx, 0, 0, n);
    }
};

// sample usage
int main(int argc, char const *argv[])
{
    vector<int> a = {1, 344, 254, 34, 54, 7, 3};
    MergeSortTree mst(a);
    cout << mst.count(2, 5, 100, 300); // count between indices 2 to 5, values betwen 100 to 300
    return 0;
}
