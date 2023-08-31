class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> neighbors (n);
        int rank, max_rank = 0;

        for(const auto& road : roads) {
            neighbors[road[0]].push_back(road[1]);
            neighbors[road[1]].push_back(road[0]);
        }

        for(int from = 0; from < n; ++from) {
            for(int to = from+1; to < n; ++to) {
                rank = neighbors[from].size() + neighbors[to].size();

                if(find(neighbors[to].begin(), neighbors[to].end(), from) != neighbors[to].end())
                    --rank;

                max_rank = max(max_rank, rank);
            }
        }

        return max_rank;
    }
};
//https://leetcode.com/problems/maximal-network-rank/