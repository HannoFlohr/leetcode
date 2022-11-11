class Solution {
private:
    bool isSubsequence(string &s, string &d) {
        int s_i = 0, d_i = 0;
        while(s_i < s.size() && d_i < d.size()) {
            if(s[s_i] == d[d_i])
                d_i++;
            
            s_i++;
        } 
        return d_i == d.size();
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string longest_word = "";
        for(auto &d : dictionary)
            if(isSubsequence(s,d)) 
                if( (longest_word.size() < d.size()) || (longest_word.size() == d.size() && d.compare(longest_word) < 0) ) 
                    longest_word = d;
        
        return longest_word;
    }
};
//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/