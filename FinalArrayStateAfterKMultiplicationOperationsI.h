class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        for(int i = 0; i < nums.size(); ++i)
            q.push({nums[i], i});
    
        while(k-- > 0) {
            auto [num, index] = q.top();
            q.pop();
            num *= multiplier;
            nums[index] = num;
            q.push({num,index});
        }

        return nums;
    }
};
//https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/