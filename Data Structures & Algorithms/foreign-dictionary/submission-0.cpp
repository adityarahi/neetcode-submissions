class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<bool> partOfWords(26, false);
        for(string& s: words) {
            for(char& c : s) {
                partOfWords[c - 'a'] = true;
            }
        }
        for(int i = 0; i < words.size() - 1; i++) {
            int n = min(words[i].size(), words[i+1].size());
            int f = 1; // first min(a.size, b.size) letters are same
            for(int j = 0; j < n; j++) {
                if(words[i][j] != words[i+1][j]) {
                    f = 0;
                    adj[words[i][j] - 'a'].push_back(words[i+1][j] - 'a');
                    break;
                }
            }
            if(f && (words[i].size() > words[i+1].size())) return "";
        }
        vector<int> in(26,0);
        for(int i = 0; i < 26; i++) {
            for(int& k : adj[i]) in[k]++;
        }
        queue<int> q;
        for(int i = 0; i < 26; i++) {
            if(partOfWords[i] && (in[i] == 0)) q.push(i);
        }
        string ans = "";
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans += (u + 'a');
            for(int v: adj[u]) {
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }
        for(int i = 0; i < 26; i++) {
            if(in[i] > 0) return "";
        }
        return ans;
    }
};
