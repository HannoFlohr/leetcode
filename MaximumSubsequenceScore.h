class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();

		//make pairs of all i in nums1/nums2, sort them by greater nums[i]
        vector<pair<int,int>> pairs (n);
        for(size_t i = 0; i < n; ++i) 
            pairs[i] = {nums2[i], nums1[i]};
        sort(pairs.rbegin(), pairs.rend());

        long long sum = 0, max_score = 0;
		//priority queue for k values for the sum of the score
        priority_queue<int, vector<int>, greater<int>> q;

        for(auto& [mult, add] : pairs) { //mult is the current minimum value for the second part of the score 
            q.emplace(add);
            sum += add;

            if(q.size() > k) { //queue above limit, remove min element from sum and pop from queue 
                sum -= q.top();
                q.pop();
            }
            if(q.size() == k) //correct size, update max_score?
                max_score = max(max_score, sum * mult);
        }

        return max_score;
    }
};
//https://leetcode.com/problems/maximum-subsequence-score/