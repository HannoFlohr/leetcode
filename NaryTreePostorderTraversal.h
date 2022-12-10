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
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        
        vector<int> result;
        vector<pair<Node*, int>> st;
        st.emplace_back(root, 0);
        
        while(!st.empty()) {
            auto &[cur, index] = st.back();
            
            if(index == cur->children.size()) {
                result.push_back(cur->val);
                st.pop_back();
            }
            else
                st.emplace_back(cur->children[index++], 0);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/n-ary-tree-postorder-traversal/