class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int middle = INT_MIN;

        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] < middle) {
                return true;
            } 
            else {
                while(!s.empty() && nums[i] > s.top()) {
                    middle = s.top();
                    s.pop();
                }
                s.push(nums[i]);
            }
        }

        return false;
    }
};	
//https://leetcode.com/problems/132-pattern/

/* brute force 89/103 testcases

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        for(int i = 0; i < n-2; ++i) {
            for(int j = i+1; j < n-1; ++j) {
                for(int k = j+1; k < n; ++k) {
                    if(nums[i] < nums[j] && nums[i] < nums[k] && nums[j] > nums[k]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
*/