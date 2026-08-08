class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        if(n == 1) return 1;
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                int x = s[i-1] - '0';
                if(x == 0 || x > 2) return 0;
                if(i > 1) dp[i] = dp[i-2];
                else dp[i] = 1;
            }
            else {
                if(s[i-1] == '0') {
                    dp[i] = dp[i-1];
                    continue;    
                }
                int x = stoi(s.substr(i-1,2));
                if(x > 0 && x < 27) {
                    if(i > 1) dp[i] = dp[i-2];
                    else dp[i] = 1;
                }
                dp[i] += dp[i-1];
            }
        }
        return dp[n-1];
    }
};
