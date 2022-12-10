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
    int maxDepth(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);
        int depth = 0, qsize;
        
        while(!q.empty()) {
            qsize = q.size();
            for(int i=0; i<qsize; i++) {
                for(auto &child : q.front()->children)
                    if(child)
                        q.push(child);
                q.pop();
            }
            depth++;
        }

        return depth;
    }
};
//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/