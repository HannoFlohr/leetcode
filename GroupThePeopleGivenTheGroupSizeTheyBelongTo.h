class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> size_to_index;

        for(int i = 0; i < groupSizes.size(); ++i) {
            size_to_index[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> groups;
        for(const auto& [size,indices] : size_to_index) {
            for(int i = 0; i < indices.size(); ) {
                vector<int> cur_group (size);
                
                for(int j = 0; j < size; ++j) {
                    cur_group[j] = indices[i];
                    ++i;
                }

                groups.push_back(cur_group);
            }
        }

        return groups;
    }
};
//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/