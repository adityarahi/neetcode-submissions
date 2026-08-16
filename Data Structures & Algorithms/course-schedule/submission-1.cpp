class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        int cnt  = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for(int v : adj[u]) {
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }
        return (cnt == numCourses);
    }
};
