/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* root = new Node(node->val);
        mp[node] = root;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(Node* nbr: curr->neighbors) {
                if(!mp.contains(nbr)) {
                    Node* newNode = new Node(nbr->val);
                    mp[nbr] = newNode;
                    q.push(nbr);
                }
                (mp[curr]->neighbors).push_back(mp[nbr]);
            }
        }
        return root;
    }
};
