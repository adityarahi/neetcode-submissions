class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(int i = 0; i < points.size(); i++) {
            pq.push({(1LL * points[i][0] * points[i][0]) + (1LL * points[i][1] * points[i][1]), i});
        }
        vector<vector<int>> ans;
        while(k--) {
            auto p = pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }
        return ans;
    }
};
