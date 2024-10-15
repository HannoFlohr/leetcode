class Solution {
public:
    int minLength(string s) {
        vector<char> q;

        for(char c : s) {
            if(!q.empty() && ((c == 'B' && q.back() == 'A') || (c == 'D' && q.back() == 'C')) )
                q.pop_back();
            else 
                q.push_back(c);
        }

        return q.size();
    }
};
//https://leetcode.com/problems/minimum-string-length-after-removing-substrings/