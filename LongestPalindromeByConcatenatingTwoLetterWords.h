class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int longest = 0, same_letter = 0;
        string reversed;
        unordered_map<string,int> candidates; 
        
        for(auto &w : words) {
            if(w[0] == w[1]) {
                if(candidates[w] > 0) {
                    longest += 4;
                    same_letter--;
                    candidates[w]--;
                }
                else {
                    same_letter++;
                    candidates[w]++;
                }
            }
            else { 
                reversed = {w[1], w[0]}; 
                if(candidates[reversed] > 0) {
                    longest += 4;
                    candidates[reversed]--;
                }
                else
                    candidates[w]++;
            }
        }
        
        if(same_letter > 0) longest += 2;
        
        return longest;
    }
};
//https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/