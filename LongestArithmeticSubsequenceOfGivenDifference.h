class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> sequence_length_at;
        int longest = 1;

        for(int& n : arr) {
            //check if the corresponding difference to the current number n was encountered before, add length for that if true
            if(sequence_length_at.find(n - difference) != sequence_length_at.end())
                sequence_length_at[n] = 1 + sequence_length_at[n-difference];  
            else
                sequence_length_at[n] = 1;
            
            longest = max(longest, sequence_length_at[n]);
        }

        return longest;
    }
};
//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/