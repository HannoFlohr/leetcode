/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private: 
    void serialize(TreeNode* root, ostringstream& out) {
        if(root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
            out << "X ";
    }

    TreeNode* deserialize(istringstream& in) {
        string cur;
        in >> cur;

        if(cur == "X")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(cur));
        node->left = deserialize(in);
        node->right = deserialize(in);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in (data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/