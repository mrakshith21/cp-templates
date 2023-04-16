#include <bits/stdc++.h>

using namespace std;

/*
    Supports 
    1. Range update
    2. Rande sum
    3. Get value at index
*/
 
class SegTree{
 
public:
 
    int left, right;
    SegTree *lChild, *rChild;
    long long int value;
    long long int lazy;
 
    SegTree(int l, int r, long long int a[]){
        left = l;
        right = r;
        lazy = 0;
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
 
    void combine(){
        value = lChild->value + rChild->value;
    }
 
    void pending(){
        if(lazy != 0){
            value += (long long int)(right - left + 1) * lazy;
            if(left != right){
                lChild->lazy += lazy;
                rChild->lazy += lazy;
            }
            lazy = 0;
        }
    }
 
    long long int get(int index){
        pending();
        if(left == right){
            return value;
        }
        if(index <= lChild->right){
            return lChild->get(index);
        }
        return rChild->get(index);
    }
 
    long long int range_sum(int l, int r){
        pending();
        if(r < left or l > right){
            return 0;
        }
        if(l <= left and right <= r){
            return value;
        }
        return lChild->range_sum(l, r) + rChild->range_sum(l, r);
    }
 
    void range_update(int l, int r, int add){
        pending();
        if(r < left or l > right){
            return;
        }
        if(l <= left and right <= r){
            value += (long long int)(right - left + 1) * add;
            if(left != right){
                lChild->lazy += add;
                rChild->lazy += add;
            }
        }
        else{
            lChild->range_update(l, r, add);
            rChild->range_update(l, r, add);
            combine();
        }
    }
};
 