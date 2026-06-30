class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size(), maxl = 0, maxr = 0;
        int l = 0, r = n-1, ans = 0;
        while(l <= r) {
            if(ht[l] <= ht[r]) {
                maxl = max(maxl, ht[l]);
                ans += (maxl - ht[l]);
                ++l;
            }
            else {
                maxr = max(maxr, ht[r]);
                ans += (maxr - ht[r]);
                r--;
            }
        }
        return ans;
    }
};
