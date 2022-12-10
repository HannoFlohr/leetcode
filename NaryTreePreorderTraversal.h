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
    vector<int> preorder(Node* root) {
        if(!root) return {};
        
        vector<int> result;
        vector<Node*> st;
        st.push_back(root);
        Node* cur;
        
        while(!st.empty()) {
            cur = st.back();
            st.pop_back();
            
            result.push_back(cur->val);
            for(int i=cur->children.size()-1; i>=0; i--) 
                if(cur->children[i])
                    st.push_back(cur->children[i]);
        }
    
        return result;
    }
};
//https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
iterative solution: use a vector of Node* as a stack 
take node from top, add value to the results and push the children on the stack in reverse order
*/