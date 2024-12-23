class Solution {
public:
    int maximumLength(string s) {
        map<string,int> substrings;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                if(s[j] != s[i])
                    break;
                ++substrings[s.substr(i, j-i+1)];
            }
        }

        int max_length = -1;
        for(auto& [sub,count] : substrings)  { 
            if(count < 3) 
                continue;
            max_length = max(max_length, (int)sub.size());
        }

        return max_length;
    }
};
//https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/