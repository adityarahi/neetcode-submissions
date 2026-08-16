class DSU {
public:
    vector<int> sz;
    vector<int> par;

    DSU(int n) {
        sz.resize(n,1);
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int n) {
        if(par[n] == n) return n;
        return par[n] = find(par[n]);
    }
    
    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if(i == j) return false;
        if(sz[i] > sz[j]) {
            sz[i] += sz[j];
            par[j] = i;
        }
        else {
            sz[j] += sz[i];
            par[i] = j;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int li = 0, n = edges.size();
        DSU obj(n);
        for(int i = 0; i < n; i++) {
            if(!obj.unite(edges[i][0] - 1, edges[i][1] - 1)) li = i;
        }
        return edges[li];
    }
};