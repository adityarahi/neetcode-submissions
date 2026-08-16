class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& adj, vector<string>& res, string u) {
        while(!adj[u].empty()) {
            string v = adj[u].back();
            adj[u].pop_back();
            dfs(adj, res, v);
        }
        res.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, vector<string>> adj;
        for(int i = 0; i < tickets.size(); i++) {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto& [src, dests] : adj) { // if you don't use symbol '&' then a separate copy is sorted
            // use by reference to sort the target vector, else you sort a copy by value
            sort(dests.rbegin(), dests.rend());
        }
        dfs(adj, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};