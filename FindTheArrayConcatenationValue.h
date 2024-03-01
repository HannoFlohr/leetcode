class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long result = 0LL;
        int front = 0, back = nums.size()-1;

        while(front < back) {
            int first = nums[front], second = nums[back];
            result += second;
            while(second > 0) {
                first *= 10;
                second /= 10;
            }
            result += first; 
            
            ++front;
            --back;
        }

        if(front == back)
            result += nums[front];

        return result;
    }
};
//https://leetcode.com/problems/find-the-array-concatenation-value/