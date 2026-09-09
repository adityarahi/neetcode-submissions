class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return 0;
        vector<unsigned int> dp(n+1,0), dpPrev(n+1,0);
        dpPrev[0] = 1;
        dp[0] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= min(i,n); j++) {
                dp[j] = dpPrev[j];
                if(s[i-1] == t[j-1]) dp[j] += dpPrev[j-1];
            }
            dpPrev = dp;
        }
        return dp[n];
    }
};
