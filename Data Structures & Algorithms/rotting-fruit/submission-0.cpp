class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,-1,0,1};
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        unordered_set<int> vis;
        int cnt_1 = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    int flat_idx = i*n + j;
                    q.push({flat_idx, 0});
                    vis.insert(flat_idx);
                }
                else if(grid[i][j] == 1) cnt_1++;
            }
        }
        int ans = 0;
        while(!q.empty()) {
            auto[flat_id , time] = q.front();
            q.pop();
            ans = max(ans, time);
            int i = flat_id / n;
            int j = flat_id % n;
            for(int it = 0; it < 4; it++) {
                int x = (i + dx[it]), y = (j + dy[it]);
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                if(vis.contains(x*n + y)) continue;
                vis.insert(x*n + y);
                if(grid[x][y] != 1) continue;
                cnt_1--;
                q.push({x*n + y, time + 1});
            }
        }
        return ((cnt_1 > 0) ? -1 : ans);
    }
};
