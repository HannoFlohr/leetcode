class Solution {
private:
    int gcds[14][14] = {};
    int memory[1 << 14] = {};
    int n, pairs;

    int gcd(const vector<int>& nums, int i, int j) {
        if(gcds[i][j] != 0)
            return gcds[i][j];
        return gcds[i][j] = __gcd(nums[i], nums[j]);
    }

    int solve(const vector<int>& nums, int operation, int mask) {
        if(operation > pairs)
            return 0;
        if(memory[mask] != 0)
            return memory[mask];

        for(int i = 0; i < n; ++i) {
            if((mask >> i) & 1) //skip, if number at i is used  
                continue;
            
            for(int j = i+1; j < n; ++j) {
                if((mask >> j) & 1) //skip, if number at j is used
                    continue;

                int newMask = (1 << i) | (1 << j) | mask; //mark numbers at i an j used
                int score = operation * gcd(nums, i, j) + solve(nums, operation+1, newMask);
                memory[mask] = max(memory[mask], score);
            }
        }

        return memory[mask];
    }

public:
    int maxScore(vector<int>& nums) {
        n = nums.size(), pairs = n/2;
        return solve(nums, 1, 0);    
    }
};
//https://leetcode.com/problems/maximize-score-after-n-operations/