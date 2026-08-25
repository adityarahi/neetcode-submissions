class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool canReach(int& t, vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = true;
        int grid_size = vis.size() - 1;
        if(i == grid_size && j == grid_size) return true;
        for(int it = 0; it < 4; it++) {
            int r = i + dx[it];
            int c = j + dy[it];
            if(r < 0 || r >= grid.size() || c < 0 || c >= grid.size()) continue;
            if(vis[r][c] || (grid[r][c] > t)) continue;
            if(canReach(t, grid, vis, r, c)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int lo = grid[0][0], hi = 2500, n = grid.size();
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if(canReach(mid, grid, vis, 0, 0)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};