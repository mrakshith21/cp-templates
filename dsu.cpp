#include <bits/stdc++.h>

using namespace std;

class dsu{
    public:
        int n;
        vector<vector<int>> boxes;
        vector<int> index;
        int components;
        dsu(int n){
            this->n = n;
            this->components = n;
            boxes = vector<vector<int>>(n);
            index = vector<int>(n);
            for(int i = 0; i < n; i++){
                index[i] = i;
                boxes[i].emplace_back(i);
            }
        }

        void merge(int i, int j){
            i = index[i];
            j = index[j];
            if(i == j)
                return;
            if(boxes[i].size() < boxes[j].size()){
                swap(i, j);
            }
            for(int x: boxes[j]){
                boxes[i].emplace_back(x);
                index[x] = i;
            }
            index[j] = i;
            boxes[j].clear();
            components--;
        }

        bool same(int i, int j){
            return index[i] == index[j];
        }

        int get_num_components(){
            return components;
        }

        vector<vector<int>> get_components(){
            vector<vector<int>> result;
            for(int i = 0; i < n; i++){
                if(!boxes[i].empty()){
                    result.emplace_back(boxes[i]);
                }
            }
            return result;
        }
};

int main(int argc, char const *argv[])
{
    int n = 100;
    dsu d(n);
    d.merge(0, 1);
    cout << d.same(0, 1); // true
    return 0;
}
