class Solution {
public:
    bool possible(vector<int>& piles, int& k, int& h) {
            long long hrs = 0, h1 = h;
            for(int i = 0; i < piles.size(); i++) {
                hrs += ((long long) piles[i] + (long long) k - 1LL) / k;
                if(hrs > h1) return false; 
            }
            return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        int ans =1 ;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(possible(piles, mid, h)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;  
        }
        return ans;
    }
};
