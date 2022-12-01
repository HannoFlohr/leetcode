class Solution {
public:
    int countSegments(string s) {
        int counter = 0;
        for(int i=0; i<s.size(); i++)
            if(s[i] != ' ' && (i == 0 || s[i-1] == ' ') )
              counter++;
        
        return counter;
    }
};
//https://leetcode.com/problems/number-of-segments-in-a-string/