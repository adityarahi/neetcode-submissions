class DSU {
public:
    vector<int> par;
    vector<int> sz;
    DSU(int n) {
        par.resize(n);
        sz.resize(n,1);
        for(int i = 0; i < n; i++) par[i] = i;
    }

    int find(int i) {
        if(par[i] == i) return i;
        else return par[i] = find(par[i]);
    }

    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if(i == j) return false;
        if(sz[i] > sz[j]) {
            par[j] = i;
            sz[i] += sz[j];
        }
        else {
            par[i] = j;
            sz[j] += sz[i];
        }
        return true;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) { // Kruskal's algorithm
        int n = points.size();
        DSU obj(n);
        vector<pair<int, pair<int,int>>> edges; // {wt, {u,v}};
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({d, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0, edge_cnt = 0;
        for(int i = 0; i < edges.size(); i++) {
            if(edge_cnt == (n-1)) break;
            int d = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
            if(!obj.unite(u,v)) continue;
            edge_cnt++;
            ans += d; 
        }
        return ans;
    }
};