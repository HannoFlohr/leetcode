class Solution {
private:
    void dfs(const vector<vector<int>>& adjacent, const string& labels, int node, int previous, 
                    vector<int>& same_label, vector<int>& char_count) {
        int count_previous = char_count[labels[node]-'a'];
        char_count[labels[node]-'a'] += 1;

        for(auto &child : adjacent[node]) { 
            if(child == previous) continue;
            dfs(adjacent, labels, child, node, same_label, char_count);
        }

        same_label[node] = char_count[labels[node]-'a'] - count_previous;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjacent (n);
        for(auto &edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
        }

        vector<int> same_label (n);
        vector<int> char_count (26, 0);
        dfs(adjacent, labels, 0, -1, same_label, char_count);

        return same_label;
    }
};
//https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/