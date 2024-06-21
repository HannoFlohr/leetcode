class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> placements (score.size(), "");
        map<int,int> scores;
        for(int i = 0; i < score.size(); ++i) {
            scores[score[i]] = i;
        }

        auto it = scores.rbegin();
        for(int rank = 0; rank < score.size(); ++rank, ++it) {
            switch(rank) {
                case 0 : placements[it->second] = "Gold Medal"; break;
                case 1 : placements[it->second] = "Silver Medal"; break;
                case 2 : placements[it->second] = "Bronze Medal"; break;
                default : placements[it->second] = to_string(rank+1); break;
            }
        }

        return placements;
    }
};
//https://leetcode.com/problems/relative-ranks/