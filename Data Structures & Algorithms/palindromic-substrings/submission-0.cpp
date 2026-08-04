class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), l = 1;
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i = 0; i < n; i++) { dp[i][i] = true; ans++; }
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) { 
                dp[i][i+1] = true; 
                ans++;
            }
        } 
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                dp[i][i+len-1] = ((s[i] == s[i+len-1]) && dp[i+1][i+len-2]);
                if(dp[i][i+len-1]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
