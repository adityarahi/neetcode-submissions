class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,double>> ps(n);
        stack<double> st;
        for(int i = 0; i < n; i++) {
            ps[i] = {position[i], (1.0 * (target - position[i])) / (1.0 * speed[i])};
        }
        sort(ps.begin(), ps.end());
        for(int i = 0; i < n; i++) {
            if(st.empty()) st.push(ps[i].second);
            else {
                double t = ps[i].second;
                while(!st.empty() && t >= st.top()) {
                    st.pop();
                }
                st.push(t);
            }
        }
        return st.size();
    }
};
