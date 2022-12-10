class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> wordIndices;
        for(int i=0; i<list1.size(); i++)
            wordIndices[list1[i]].push_back(i);
        for(int i=0; i<list2.size(); i++)
            wordIndices[list2[i]].push_back(i);
            
        int min_index_sum = INT_MAX, cur_sum;
        vector<string> result;
        
        for(auto &i : wordIndices) {
            if(i.second.size() != 2) continue;
            
            cur_sum = i.second[0] + i.second[1];
            
            if(cur_sum < min_index_sum) {
                min_index_sum = cur_sum;
                result.clear();
                result.push_back(i.first);
            }
            else if(cur_sum == min_index_sum)
                result.push_back(i.first);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/minimum-index-sum-of-two-lists/