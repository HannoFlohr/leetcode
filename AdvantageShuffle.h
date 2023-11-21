class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> shuffle;
        
        multiset<int> values1;
        for(int num : nums1) {
            values1.insert(num);
        } 

        for(int num : nums2) {
            auto it = values1.upper_bound(num);
            if(it != values1.end()) {
                shuffle.push_back(*it);
                values1.erase(it);
            }
            else {
                shuffle.push_back(*values1.begin());
                values1.erase(values1.begin());
            }
        }

        return shuffle;
    }
};
//https://leetcode.com/problems/advantage-shuffle/