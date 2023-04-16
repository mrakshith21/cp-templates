#include <bits/stdc++.h>

using namespace std;

/*
    Supports 
    1. Range addition
    2. Get value at index
    3. Update value at index
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
 
    long long int range_sum(int l, int r){
        if(r < left or l > right){
            return 0;
        }
        if(l <= left and right <= r){
            return value;
        }
        
        return lChild->range_sum(l, r) + rChild->range_sum(l, r);
    }    
};
 