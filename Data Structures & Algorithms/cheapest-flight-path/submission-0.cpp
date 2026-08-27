class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int>& edge : flights) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int stops = 0;
        queue<pair<int,int>> q;
        q.push({src, 0});
        while((stops <= k) && !q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto p = q.front();
                int u = p.first, dist_u = p.second;
                q.pop();
                for(auto& it: adj[u]) {
                    int v = it.first, wt = it.second;
                    if((dist_u + wt) >= dist[v]) continue;
                    dist[v] = dist_u + wt;
                    q.push({v, dist[v]});
                }
            }
            stops++;
        }
        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
};
