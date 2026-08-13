class Solution {
public:
vector<int> dx{{-1,0,1,0}};
    vector<int> dy{{0,-1,0,1}};
    int ans{0};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '2';
        for(int it = 0; it < 4; it++) {
            int x = i + dx[it];
            int y = j + dy[it];
            if((x < 0) || (x >= grid.size()) || (y < 0) || (y >= grid[0].size())) continue;
            if(grid[x][y] == '0' || grid[x][y] == '2') continue;
            dfs(x, y, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '0' || grid[i][j] == '2') continue;
                dfs(i, j, grid);
                ans++;
            }
        }
        return ans;
    }
};
