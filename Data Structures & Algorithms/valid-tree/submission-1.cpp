class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(n == 1) return (m == 0);
        if((n-1) != m) return false;
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i< n; i++) {
            if(deg[i] == 1) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for(int v: adj[u]) {
                deg[v]--;
                if(deg[v] == 1) q.push(v); 
            }
        }
        return (cnt == n);
    }
};
