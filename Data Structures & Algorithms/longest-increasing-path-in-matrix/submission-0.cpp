class Solution {
public:
    vector<int> dx{{-1,0,1,0}};
    vector<int> dy{{0,-1,0,1}};
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        for(int it = 0; it < 4; it++) {
            int x = i + dx[it], y = j + dy[it];
            if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()) continue;
            if(mat[x][y] > mat[i][j]) dp[i][j] = max(dp[i][j], 1 + dfs(x,y,dp,mat));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] == -1) {
                    dfs(i,j,dp,matrix);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};