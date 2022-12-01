/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL; 
        
        queue<Node*> q;
        q.push(root);
        int qsize;
        Node* cur;
        while(!q.empty()) {
            qsize = q.size();
            for(int i=0; i<qsize; i++) {
                cur = q.front();
                q.pop();
                
                if(i < qsize-1) cur->next = q.front();
                
                if(cur->left) q.push(cur->left), q.push(cur->right);
            }
        }
        
        return root;
    }
};
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/