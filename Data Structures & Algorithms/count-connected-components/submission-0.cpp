class DSU {
public:
    vector<int> sz;
    vector<int> par;
    int numClust;

    DSU(int n) : numClust(n) {
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
    
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if(i == j) return;
        if(sz[i] > sz[j]) {
            sz[i] += sz[j];
            par[j] = i;
        }
        else {
            sz[j] += sz[i];
            par[i] = j;
        }
        numClust--;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        DSU obj(n);
        for(int i = 0; i < m; i++) {
            obj.unite(edges[i][0], edges[i][1]);
        }
        return obj.numClust;
    }
};
