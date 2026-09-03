class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26, -1), ans;
        for(int i = 0; i < s.size(); i++) {
            last_index[s[i] - 'a'] = i;
        }
        for(int i = 0; i < s.size(); i++) {
            int j = i, last_i = last_index[s[i] - 'a'];
            while((j != last_i) && (j < s.size())) {
                last_i = max(last_i, last_index[s[j] - 'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i = j;
        }
        return ans;
    }
};
