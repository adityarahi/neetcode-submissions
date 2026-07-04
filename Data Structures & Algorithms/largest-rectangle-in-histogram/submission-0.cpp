class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n), right(n); // get next smallest height idx in both directions
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && h[i] < h[s.top()]) {
                int j = s.top();
                s.pop();
                right[j] = i;
            }
            s.push(i);
        }
        while(!s.empty()) {
            right[s.top()] = n; // edge case
            s.pop();
        }
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && h[i] < h[s.top()]) {
                int j = s.top();
                s.pop();
                left[j] = i;
            }
            s.push(i);
        }
        while(!s.empty()) {
            left[s.top()] = -1; // edge case
            s.pop();
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (right[i] - left[i] - 1) * h[i]); // calculate area
        }
        return ans;
    }
};
