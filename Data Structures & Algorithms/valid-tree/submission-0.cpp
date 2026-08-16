class Solution {
public:
    bool hasCycle(int u, int p, vector<vector<int>>& adj, vector<int>& vis) {
        if(vis[u] == 1) return true;
        vis[u] = 1;
        for(int v: adj[u]) {
            if((vis[v] == 2) || (v == p)) continue;
            if(hasCycle(v, u, adj, vis)) return true;
        }
        vis[u] = 2;
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != (n-1)) return false;
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(hasCycle(i,-1,adj,vis)) return false;
        }
        return true;
    }
};
