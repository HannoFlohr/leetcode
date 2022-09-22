class Solution {
public:
    string reverseStr(string s, int k) {
        for(int start=0; start<s.size(); start += 2*k) 
            for(int left=start, right=min(start+k-1, (int)s.size()-1); left<right; left++, right--)
                swap(s[left], s[right]);
        
        return s;
    }
};
//https://leetcode.com/problems/reverse-string-ii/