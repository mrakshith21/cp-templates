#include <bits/stdc++.h>

using namespace std;

/*
    Sparse table implementation
    From CP-Algorithms [https://cp-algorithms.com/data_structures/sparse-table.html]
*/
class SparseTable{
    const int K = 20;

    public:
        vector<vector<long long int>> table;
        vector<int> lg;
        int n;

        long long int combine(long long int a, long long int b){
            return min(a, b);
        }

        void init_logs(){
            lg = vector<int>(n + 1);
            lg[1] = 0;
            for(int i = 2; i <= n; i++){
                lg[i] = lg[i / 2] + 1;
            }
        }

        void init(vector<int>& a){
            this->n = a.size();
            table = vector<vector<long long int>>(n, vector<long long int>(K));
            copy(a.begin(), a.end(), table[0].begin());
            for(int i = 1; i < K; i++){
                for(int j = 0; j + (1 << i) < n; j++){
                    table[i][j] = combine(table[i][j - 1], table[i + (1 << (i - 1))][j - 1]);
                }
            }
        }

        long long int query(int l, int r){
            int i = lg[r - l + 1];
            return combine(table[l][i], table[r - (1 << i) + 1][i]);
        }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
