class Solution {
public:
    string customSortString(string order, string s) {
        string result = "";
        unordered_map<char,int> chars;
        
        //count chars in s;
        for(char c : s){
            chars[c]++;
        }        
        //for each char in order check if it is present in s and append it to result if true
        for(char c : order) {
            while(chars[c]-- > 0) {
                result += c;
            }
        }
        //add remaining chars of s
        for(auto [ch,freq] : chars) {
            while(freq-- > 0) {
                result += ch;
            }
        }

        return result; 
    }
};
//https://leetcode.com/problems/custom-sort-string/