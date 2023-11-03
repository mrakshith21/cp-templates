#include <bits/stdc++.h>

using namespace std;

// returns index of nearest smaller element towards the left
// -1 if it does not exist
// strict -> strictly smaller if true
vector<int> nearest_smaller_left(vector<int>& a, bool strict = true){
    stack<int> st;
    int n = a.size();
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        while(!st.empty()){
            if(a[st.top()] > a[i] || (strict and a[st.top()] == a[i]))
                st.pop();
            else
                break;
        }
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// returns index of nearest larger element towards the left
// -1 if it does not exist
// strict -> strictly larger if true
vector<int> nearest_larger_left(vector<int>& a, bool strict = true){
    stack<int> st;
    int n = a.size();
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        while(!st.empty()){
            if(a[st.top()] < a[i] || (strict and a[st.top()] == a[i]))
                st.pop();
            else
                break;
        }
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// returns index of nearest smaller element towards the right
// n if it does not exist
// strict -> strictly smaller if true
vector<int> nearest_smaller_right(vector<int>& a, bool strict = true){
    stack<int> st;
    int n = a.size();
    vector<int> ans(n, n);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty()){
            if(a[st.top()] > a[i] || (strict and a[st.top()] == a[i]))
                st.pop();
            else
                break;
        }
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// returns index of nearest larger element towards the right
// n if it does not exist
// strict -> strictly larger if true
vector<int> nearest_larger_right(vector<int>& a, bool strict = true){
    stack<int> st;
    int n = a.size();
    vector<int> ans(n, n);
    for(int i = n - 1; i >= 0; i--){{
        while(!st.empty()){
            if(a[st.top()] < a[i] || (strict and a[st.top()] == a[i]))
                st.pop();
            else
                break;
        }
        if(!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}