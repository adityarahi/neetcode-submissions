class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int &x = target[0], &y = target[1], &z = target[2];
        int a1 = 0, b1 = 0, c1 = 0;
        for(vector<int>& trip : triplets) {
            if(trip[0] > x || trip[1] > y || trip[2] > z) continue;
            if(trip[0] == x) a1 = 1;
            if(trip[1] == y) b1 = 1;
            if(trip[2] == z) c1 = 1;
        }
        return (a1 & b1 & c1);
    }
};
