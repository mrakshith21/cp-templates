#include <bits/stdc++.h>

using namespace std;

/*
    Supports 
    1. Range addition
    2. Get value at index
    3. Update value at index

    Please note to modify the lines marked with
        'MODIFY this based on the problem'
    based on the problem
*/
 
class SegTree{
 
public:
 
    int left, right;
    SegTree *lChild, *rChild;
    long long int value;
 
    SegTree(int l, int r, long long int a[]){
        left = l;
        right = r;
        if(l == r){
            value = a[l];
        }
        else{
            int mid = (l + r) >> 1;
            lChild = new SegTree(l, mid, a);
            rChild = new SegTree(mid + 1, r, a);
            combine();
        }
    }
 
    // MODIFY this based on the problem
    void combine(){
        value = lChild->value + rChild->value;
    }
 
    long long int get(int index){
        if(left == right){
            return value;
        }
        if(index <= lChild->right){
            return lChild->get(index);
        }
        return rChild->get(index);
    }

    void update(int index, int newVal){
        if(left == right){
            value = newVal;
            return;
        }
        if(lChild -> right >= index){
            lChild -> update(index, newVal);
        }
        else{
            rChild -> update(index, newVal);
        }
        combine();
    }
 
    long long int range_query(int l, int r){
        if(r < left or l > right){
            // MODIFY this based on the problem
            return 0;
        }
        if(l <= left and right <= r){
            return value;
        }
        
        // MODIFY this based on the problem
        return lChild->range_query(l, r) + rChild->range_query(l, r);
    }    
};

// Array compression
// returns the new array with compressed values
vector<int> compress_array(vector<int>& a){
    int n = a.size();
    set<int> s(a.begin(), a.end());
    vector<int> result(n);
    map<int, int> idx;
    int cnt = 0;
    for(int x: s)
        idx[x] = cnt++;
    for(int i = 0; i < n; i++)
        result[i] = idx[a[i]];
    return result;
}