class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        //sort all start and end times for the bloom of all flowers
        vector<int> start, end;
        for(auto& flower : flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> in_bloom (people.size());
        int started, ended;
        //for each person use binary search to find upper bound of started flowers and lower bound of ended flowers
        for(int i = 0; i < people.size(); i++) {
            in_bloom[i] = (upper_bound(start.begin(), start.end(), people[i]) - start.begin()) -
                            (lower_bound(end.begin(), end.end(), people[i]) - end.begin());
        }

        return in_bloom;
    }
};
//https://leetcode.com/problems/number-of-flowers-in-full-bloom/