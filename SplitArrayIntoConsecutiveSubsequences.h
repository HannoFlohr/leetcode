class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto n:nums)
            freq[n]++;
        
        unordered_map<int,int> subsequence_ends;
        for(auto n:nums) {
            if(freq[n] == 0) continue; 
            
            //n can be used in an existing subsequence
            if(subsequence_ends[n-1] > 0){
                subsequence_ends[n-1]--;
                subsequence_ends[n]++;
            }
            //start new subsequence with n of length 3 if possible
            else if(freq[n+1]>0 && freq[n+2] > 0) {
                subsequence_ends[n+2]++;
                freq[n+1]--;
                freq[n+2]--;
            }
            else 
                return false;
            
            freq[n]--;
        }
        
        
        return true;
    }
};
//https://leetcode.com/problems/split-array-into-consecutive-subsequences/