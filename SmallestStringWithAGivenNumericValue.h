class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;

        while(n > 0) {
            int c = k - (n-1)*26;
            if(c <= 0) {
                s.push_back('a');
                --k;
            }
            else {
                s.push_back(c+'a'-1);
                k -= c;
            }
            --n;
        }
        
        return s;
    }
};
//https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/