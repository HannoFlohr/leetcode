class BinaryIndexedTree {
private:
    vector<int> bit;
public:
    BinaryIndexedTree(int size=0) : bit(vector<int>(size+1, 0)) {}
    
    void add_value(int index, int value) {
        for( ; index<bit.size(); index += index & (-index)) 
            bit[index] += value; 
    }
    
    int prefix_sum(int index) {
        int sum = 0;
        for( ; index>0; index -= index & (-index))
            sum += bit[index];
        return sum;
    }
};

class NumArray {
private:
    BinaryIndexedTree BIT;
    vector<int> numbers;
public:
    NumArray(vector<int>& nums) {
        BIT = BinaryIndexedTree(nums.size());
        numbers = nums;
        for(int i=0; i<nums.size(); i++)
            BIT.add_value(i+1, numbers[i]);
    }
    
    void update(int index, int val) {
        BIT.add_value(index+1, val - numbers[index]); //add the difference at index+1
        numbers[index] = val;
    }
    
    int sumRange(int left, int right) {
        return BIT.prefix_sum(right+1) - BIT.prefix_sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
 
 //https://leetcode.com/problems/range-sum-query-mutable/
 
 //https://en.wikipedia.org/wiki/Fenwick_tree - concept of binary indexed tree