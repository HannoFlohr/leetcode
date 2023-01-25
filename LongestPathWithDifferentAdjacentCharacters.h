class Solution {
private:
    int dfs(const string& s, const vector<vector<int>>& children, int node, int& longest_path) { 
        int cur, first = 0, second = 0;
        
        for(auto &child : children[node]) {
            cur = dfs(s, children, child, longest_path);

            if(s[node] == s[child]) continue;
            if(cur > second)
                second = cur;
            if(second > first)
                swap(first, second);
        }

        longest_path = max(longest_path, first+second+1);

        return first+1;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        int longest_path = 0;
        vector<vector<int>> children (s.size(), vector<int>());
        for(int i=1; i<s.size(); i++)
            children[parent[i]].push_back(i);
        
        dfs(s, children, 0, longest_path);
    
        return longest_path;
    }
};
//https://leetcode.com/problems/longest-path-with-different-adjacent-characters/