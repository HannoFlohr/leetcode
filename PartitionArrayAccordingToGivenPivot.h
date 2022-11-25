class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        stack<int> before;
        stack<int> after;
        int pivots = 0;
        
        for(auto &n : nums) {
            if(n < pivot) before.push(n);
            else if(n > pivot) after.push(n);
            else pivots++;
        }
        
        int i = nums.size()-1;
        while(!after.empty()) {
            nums[i--] = after.top();
            after.pop();
        }
        while(pivots--)
            nums[i--] = pivot;
        while(!before.empty()) {
            nums[i--] = before.top();
            before.pop();
        }  
        
        return nums;
    }
};
//https://leetcode.com/problems/partition-array-according-to-given-pivot/
// two approaches; below had faster run time and less memory

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        for(auto &n : nums) 
            if(n < pivot) low++;
            else if(n == pivot) same++;
        
        high = low + same;
        same = low;
        low = 0;
        
        vector<int> sorted (nums.size());
        for(auto &n : nums) 
            if(n < pivot)
                sorted[low++] = n;
            else if(n == pivot)
                sorted[same++] = n;
            else
                sorted[high++] = n;
        
        return sorted;
    }
};