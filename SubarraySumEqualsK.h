class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int equal_k = 0, sum=0, difference;
        
		//used to store <sum that was found, times that sum was found>
        unordered_map<int,int> sum_freq;
        sum_freq[sum] = 1;
        
        for(const auto &n : nums) {
            sum += n;
            difference = sum - k;
			//check if the needed sum difference was found before and add times it occured to the result if true
            if(sum_freq[difference] > 0)
                equal_k += sum_freq[difference];
            
			//increment frequency of the sum found in this step
            sum_freq[sum]++;
        }

        return equal_k;
    }
};
//https://leetcode.com/problems/subarray-sum-equals-k/