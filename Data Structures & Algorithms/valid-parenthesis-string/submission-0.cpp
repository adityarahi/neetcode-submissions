class Solution {
public:
    bool check(int i, int stck, vector<vector<int>>& dp, string& s) {
        if(i == s.size()) { return (stck == 0); }
        std::cout << "i: " << i << ", stck: " << stck << "\n";
        if(dp[i][stck] != -1) return dp[i][stck];
        if(s[i] == '(') {
            if(check(i+1, stck + 1, dp, s)) return (dp[i][stck] = 1);
        }
        else if(s[i] == ')') {
            if(stck == 0) {
                return dp[i][stck] = 0;
            }
            else {
                if(check(i+1, stck - 1, dp, s)) return (dp[i][stck] = 1);
            }
        }
        else {
            if(check(i+1, stck+1, dp, s)) return (dp[i][stck] = 1); // '*' is '('
            if(check(i+1, stck, dp, s)) return (dp[i][stck] = 1); // '*' is ''
            if(stck > 0 && check(i+1, stck - 1, dp, s)) return (dp[i][stck] = 1); // '*' is ')'
        }
        return dp[i][stck] = 0;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return check(0, 0, dp, s);
    }
};
