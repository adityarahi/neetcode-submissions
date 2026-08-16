class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, int u, vector<int>& vis) {
        if(vis[u] == 1) return true; // already in function call stack, cycle detected
        vis[u] = 1; // add to function call stack
        for(int v: adj[u]) {
            if(vis[v] == 2) continue; // was already visited in some other dfs call
            if(hasCycle(adj, v, vis)) return true;
        }
        vis[u] = 2; // remove from dfs call stack, but mark as visited
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(vis[i]) continue;
            if(hasCycle(adj, i, vis)) return false;
        }
        return true;
    }
};
