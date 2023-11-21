class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > k_largest_elements;
        for(int i = 0; i < nums.size(); ++i) {
            k_largest_elements.push({nums[i], i});

            if(k_largest_elements.size() > k) {
                k_largest_elements.pop();
            }
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > k_largest_elements_by_index;
        while(!k_largest_elements.empty()) {
            k_largest_elements_by_index.push({k_largest_elements.top().second, k_largest_elements.top().first});
            k_largest_elements.pop();
        }

        vector<int> subsequence;
        while(!k_largest_elements_by_index.empty()) {
            subsequence.push_back(k_largest_elements_by_index.top().second);
            k_largest_elements_by_index.pop();
        }

        return subsequence;
    }
};
//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/