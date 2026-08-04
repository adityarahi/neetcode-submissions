class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans = {1,1};
        if(n < 2) return ans[n];
        for(int i = 2; i <= n; i++) {
            int tmp = ans[0] + ans[1];
            ans[0] = ans[1]; ans[1] = tmp;
        }
        return ans[1];
    }
};
