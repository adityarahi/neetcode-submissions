class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1; // handle corner case;
        // in general, dp[i] is # ways to decode string with s[i ... (n-1)]
        for(int i = n-1; i >= 0; i--) {
            // handle leading zeros; add ways only if s[i] is not zero
            if(s[i] != '0') dp[i] += dp[i+1];
            // (i + 1 < n) is to compare with next string element s[n] is out of bounds
            // check if (1 to 26) can be made using s[i ... (i+1)]
            if((i+1 < n) && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};
