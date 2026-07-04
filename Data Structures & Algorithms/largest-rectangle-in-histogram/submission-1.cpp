class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        int ans = 0;
        for(int i = 0; i <= n; i++) {
            int curr_ht = (i == n) ? 0 : h[i];
            while(!s.empty() && curr_ht < h[s.top()]) {
                int ht = h[s.top()]; // ht ofthis index
                // rightmost boundary is i
                s.pop();
                // leftmost boundary is in new top of stack.
                // If stack is empty, then we encounter smallest ht so far 
                // so the width spans from the beginning to the current index 'i'
                int wd = (s.empty() ? i : (i - s.top() - 1));
                ans = max(ans, wd * ht);
            }
            s.push(i);
        }
        return ans;
    }
};
