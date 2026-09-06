class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> sorted_q(queries.begin(), queries.end());
        sort(sorted_q.begin(), sorted_q.end());
        sort(intervals.begin(), intervals.end());
        vector<int> ans(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // minHeap
        int i = 0;
        map<int,int> res;
        for(int& q: sorted_q) {
            while(i < intervals.size()) {
                if(intervals[i][0] <= q) {
                    pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                }
                else break;
                i++;
            }
            while(!pq.empty() && pq.top().second < q) pq.pop();
            res[q] = (pq.empty() ? -1 : pq.top().first);
        }
        for(int i = 0; i < n; i++) ans[i] = res[queries[i]];
        return ans;
    }
};
