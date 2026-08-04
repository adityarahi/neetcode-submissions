class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 2) return min(cost[0], cost[1]);
        vector<int> ans = {0,0};
        for(int i = 2; i <= n; i++) {
            int tmp = min(ans[0] + cost[i-2], ans[1] + cost[i-1]);
            ans[0] = ans[1]; ans[1] = tmp;
        }
        return ans[1];
    }
};
