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
private:
    unordered_map<Node*,Node*> clones;

    void dfs(Node* node) {
        Node* clone = new Node(node->val);
        clones[node] = clone;

        for(auto neighbor : node->neighbors) {
            if(clones.find(neighbor) == clones.end())
                dfs(neighbor);

            clone->neighbors.push_back(clones[neighbor]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        clones.clear();
        dfs(node);
        return clones[node];
    }
};
//https://leetcode.com/problems/clone-graph/