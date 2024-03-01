/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void setGraph(TreeNode* root, unordered_map<int,vector<int>>& graph) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});

        while(!q.empty()) {
            auto [node,parent] = q.front();
            q.pop();

            if(parent != -1) {
                graph[parent].push_back(node->val);
                graph[node->val].push_back(parent);
            } 
            if(node->left != nullptr)
                q.push({node->left, node->val});
            if(node->right != nullptr)
                q.push({node->right, node->val});
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> graph;
        setGraph(root, graph);

        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        int node, qsize, time_to_infect = 0;

        while(!q.empty()) { 
            qsize = q.size(); 

            while(qsize--) {
                node = q.front();
                q.pop();

                for(int next : graph[node]) {
                    if(visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }

            ++time_to_infect;
        }

        return time_to_infect - 1;
    }
};
//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/