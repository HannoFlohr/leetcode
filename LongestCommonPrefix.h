class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];

        for(unsigned i=1; i<strs.size(); i++) {
            unsigned j=0;
            for( ; j<strs[i].size(); j++) 
                if(lcp[j] != strs[i][j])
                    break;
            
            lcp = lcp.substr(0,j);
            if(lcp == "")
                break;
        }
        
        return lcp;
    }
};
//https://leetcode.com/problems/longest-common-prefix/

/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        char c;
        bool sameChar;
        
        auto smin = *min_element(strs.begin(), strs.end(), 
                     [] (const string& s1, const string& s2) { 
                         return s1.length() < s2.length(); }
                     );
        unsigned shortestWord = smin.size();
        
        for(unsigned i=0; i<shortestWord; i++) {
            c = strs[0][i];
            sameChar = true;
            
            for(unsigned j=1; j<strs.size(); j++)
                if(strs[j][i] != c) {
                    sameChar = false;
                    break;
                }
            
            if(!sameChar) 
                break;
            
            lcp += c;
        }
        
        return lcp;
    }
};
*/