class Solution {
private:
    const int MAXN = 10000;
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> has_number (2*MAXN+1, 0);
        for(auto &n : nums)
            has_number[n + MAXN]++;
        
        int sum = 0;
        bool first = true;
        for(int i=0; i<has_number.size(); i++)
            while(has_number[i] > 0) {
                if(first)
                    sum += i - MAXN;
                
                has_number[i]--;
                first = !first;
            }
        
        return sum;
    }
};
//https://leetcode.com/problems/array-partition/

/*

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size()-1; i+=2) 
            sum += min(nums[i], nums[i+1]);
        return sum;
    }
};

*/