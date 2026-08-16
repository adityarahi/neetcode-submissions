class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.insert(beginWord);
        int L = beginWord.size();
        q.push({beginWord, 1});
        while(!q.empty()) {
            auto [u, d] = q.front(); // u node, d distance
            if(u == endWord) return d;
            q.pop();
            for(int i = 0; i < L; i++) {
                string v = u;
                for(char c = 'a'; c <= 'z'; c++) {
                    v[i] = c;
                    if(st.contains(v)) {
                        st.erase(v);
                        q.push({v,d+1});
                    }
                }
            }
        }
        return 0;
    }
};
