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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, bool> is_child;

        for(vector<int>& description : descriptions) {
            //create new node for parent if it doesnt exist
            if(nodes.find(description[0]) == nodes.end()) {
                TreeNode* node = new TreeNode(description[0]);
                nodes[description[0]] = node;
            }
            //create new node for child if it doesnt exist
            if(nodes.find(description[1]) == nodes.end()) {
                TreeNode* node = new TreeNode(description[1]);
                nodes[description[1]] = node;
            }
            //set child not at parent node
            if(description[2] == 1) {
                nodes[description[0]]->left = nodes[description[1]];
            }
            else {
                nodes[description[0]]->right = nodes[description[1]];
            }

            //mark child in the map
            is_child[description[1]] = true;
        }

        //find root node == node with no parent
        TreeNode* root = nullptr;
        for(vector<int>& description : descriptions) { 
            if(is_child[description[0]] == false) {
                root = nodes[description[0]];
                break;
            }
        }

        return root;
    }
};
//https://leetcode.com/problems/create-binary-tree-from-descriptions/