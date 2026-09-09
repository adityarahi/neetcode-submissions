class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return 0;
        // dp[i][j] = from first 'i' indices of s, and using j of them,
        // no. of distinct subsequences formed that equals to t[0 ... (j-1)]
        vector<vector<unsigned int>> dp(m+1, vector<unsigned int>(n+1, 0));
        for(int i = 0; i <= m; i++) dp[i][0] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= min(i, n); j++) {
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
