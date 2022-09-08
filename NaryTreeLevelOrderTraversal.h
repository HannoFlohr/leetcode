/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    
void dfs(Node* node, int level, vector<vector<int>>& result) {
    if(level == result.size()) 
        result.emplace_back();
    
    result[level].push_back(node->val);
    
    for(auto c : node->children)
        dfs(c, level+1, result);
}
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
    
        if(root != NULL){        
            int level = 0;
            dfs(root, level, result);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/n-ary-tree-level-order-traversal/