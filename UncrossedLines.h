class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		//first vector needs to be >= second, swap if not
        if(nums1.size() < nums2.size())
            swap(nums1, nums2);

        const int size1 = nums1.size(), size2 = nums2.size();
        vector<int> dp (size2+1, 0);
        int current, previous;

		/*
		for each number i in nums1, starting at 1 
		look for possible uncrossed lines for i-1 at all positions j in nums2
		- if uncrossed line is found set dp[j] to number of previous uncrossed lines + 1
		- else maximize value in dp[j] (max of uncrossed lines at j-1 and the possible uncrossed lines before this j) 
		*/
        for(int i = 1; i <= size1; ++i) {
            previous = 0;

            for(int j = 1; j <= size2; ++j) {
                current = dp[j];

                if(nums1[i-1] == nums2[j-1])
                    dp[j] = previous + 1;
                else
                    dp[j] = max(dp[j-1], current);

                previous = current;
            }
        }
    
        return dp[size2];
    }
};
//https://leetcode.com/problems/uncrossed-lines/