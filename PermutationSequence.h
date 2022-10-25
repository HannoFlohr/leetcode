class Solution {
public: 
    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1; i<=n; i++)
            s += to_string(i);
        
        k--;
        do {
            k--;
        } while(next_permutation(s.begin(), s.end()) && k);
        
        return s;
    }
};
//https://leetcode.com/problems/permutation-sequence/