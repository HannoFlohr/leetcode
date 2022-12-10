class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> next;
        stack<int> candidates;
        for(int i=nums2.size()-1; i>=0; i--) {
            while(!candidates.empty() && candidates.top() < nums2[i])
                candidates.pop();
            
            next[nums2[i]] = (candidates.empty()) ? -1 : candidates.top();
            
            candidates.push(nums2[i]);
        }
        
        vector<int> result;
        for(auto &n : nums1)
            result.push_back( next[n] );
        
        return result;
    }
};
//https://leetcode.com/problems/next-greater-element-i/