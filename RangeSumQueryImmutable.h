class NumArray {
private:
    vector<int> sum = vector<int>(1,0);
public:
    NumArray(vector<int>& nums) {
        for(int &n : nums)
            sum.push_back(n + sum.back());
    }
    
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

//https://leetcode.com/problems/range-sum-query-immutable/

/*
class NumArray {
private:
    int n;
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        sum = nums; 
        for(int i=1; i<n; i++)
            sum[i] += sum[i-1];
    }
    
    int sumRange(int left, int right) {
        return sum[right] - (left==0 ? 0 : sum[left-1]); 
    }
};
*/