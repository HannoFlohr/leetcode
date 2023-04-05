class Solution {
public:
    string customSortString(string order, string s) {
        string result = "";
        unordered_map<char,int> chars;
        
        //count chars in s;
        for(const auto& c : s)
            chars[c]++;        
        //for each char in order check if it is present in s and append it to result if true
        for(const auto& c : order) {
            for(size_t j=0; j<chars[c]; j++)
                result += c;
            chars[c] = 0;
        }
        //add remaining chars of s
        for(const auto& it : chars) {
            if(it.second == 0) continue;

            for(size_t j=0; j<it.second; j++) 
                result += it.first;
        }

        return result; 
    }
};
//https://leetcode.com/problems/custom-sort-string/