class Solution {
private: 
    //returns true if b is substring of a
    bool isSubstringOf(string &a, string &b) {
        if(b.size() < a.size()) return false;
        
        int equal = 0;
        for(auto &c : b)
            if(equal < a.size() && a[equal] == c)
                equal++;
        
        return equal == a.size();
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        if(strs.empty()) return -1;
        
        int longest = -1, j;
        for(int i=0; i<strs.size(); i++) {
            j = 0;
            //search a strs[j] that is substring of strs[i]
            for( ; j<strs.size(); j++) {
                if(i==j) continue; 
                if(isSubstringOf(strs[i], strs[j])) break; 
            }
            
            if(j==strs.size()) 
                longest = max(longest, (int)strs[i].size());
        }
        
        return longest;
    }
};
//https://leetcode.com/problems/longest-uncommon-subsequence-ii/