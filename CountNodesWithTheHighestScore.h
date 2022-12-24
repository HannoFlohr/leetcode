class Solution {
private:
    int dfs(vector<vector<int>>& children, vector<long long>& scores, const int& index) {
        long long score = 1, sum_nodes = 1, count_nodes;

        for(int child : children[index]) {
            count_nodes = dfs(children, scores, child); 
            sum_nodes += count_nodes;
            score *= count_nodes;
        }

        scores[index] = score * (max(1LL, (long long)children.size() - sum_nodes));

        if(index != 0)
            return sum_nodes;
        else 
            return count(scores.begin(), scores.end(), *max_element(scores.begin(), scores.end()));
    }

public:
    int countHighestScoreNodes(vector<int>& parents) {
        const int n = parents.size();
        vector<vector<int>> children (n);
        vector<long long> scores (n);
        
        for(int i=1; i<n; i++)
            children[parents[i]].push_back(i);

        return dfs(children, scores, 0);
    }
};
//https://leetcode.com/problems/count-nodes-with-the-highest-score/