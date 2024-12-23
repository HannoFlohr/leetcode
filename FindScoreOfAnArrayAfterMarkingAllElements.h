class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int n = nums.size(); 
        long long int sum = 0;
        vector<int> marked (n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i = 0; i < n; ++i)
            q.push({nums[i], i});

        while(!q.empty()) { 
            auto [number, index] = q.top();
            q.pop();

            if(marked[index])
                continue;

            sum += number;
            marked[index] = true;
            if(index > 0)
                marked[index-1] = true;
            if(index < n-1) 
                marked[index+1] = true;
        }

        return sum;
    }
};
//https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/