class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        vector<int> ans(temp.size(), 0);
        for(int i = 0; i < temp.size(); i++) {
            if(s.empty()) s.push(i);
            else if(temp[i] <= temp[s.top()]) s.push(i);
            else {
                while(!s.empty() && temp[i] > temp[s.top()]) {
                    int j = s.top();
                    ans[j] = i - j;
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()) {
            ans[s.top()] = 0;
            s.pop();
        }
        return ans;
    }
};
