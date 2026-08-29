class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<bool> pushed(26,false);
        vector<int> freq(26,0);
        for(char& c : tasks) freq[c - 'A']++;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], i});
                pushed[i] = true;
            }
        }
        int ans = 0;
        while(!pq.empty()) {
            int cnt = 0;
            for(int it = 0; it <= n; it++) { // cycles of length (n+1)
                if(pq.empty()) break;
                auto p = pq.top();
                pq.pop();
                int cnt_i = p.first, i = p.second;
                freq[i]--;
                cnt++;
                pushed[i] = false;  
            }
            for(int i = 0; i < 26; i++) {
                if(!pushed[i] && (freq[i] > 0)) {
                    pq.push({freq[i], i});
                    pushed[i] = true;
                }
            }
            if(pq.empty()) ans += cnt;
            else ans += (n+1);
        }
        return ans;
    }
};
