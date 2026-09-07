class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sold = INT_MIN, held = INT_MIN, reset = 0;
        for(int& p: prices) {
            int prevSold = sold;
            sold = held + p;
            held = max(held, reset - p);
            reset = max(reset, prevSold);
        }
        return max(sold, reset);
    }
};
