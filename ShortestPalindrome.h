class Solution {    
private:
    vector<int> kmp(string &s) {
        vector<int> p (s.size(), 0); //lookup table
        
        //index of matched char in prefix part
        int index = 0;
        //start at 1, no match with itself
        for(int i=1; i<s.size(); i++) {
            if(s[index] == s[i]) {
                p[i] = p[i-1] + 1; //extend match
                index++;
            }
            else { //match failed, try to match shorter substring
                index = p[i-1];
                
                while(index > 0 && s[index] != s[i])
                    index = p[index-1];
                
                //check for match at index/i
                if(s[index] == s[i])
                    index++;
                
                p[i] = index;
            }
        }
        
        return p;
    }
public:
    string shortestPalindrome(string s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        if(s == reversed) return s;
        
        string tmp = s + '#' + reversed;
        vector<int> p = kmp(tmp);
        
        string missing = s.substr(p[p.size()-1]);
        reverse(missing.begin(), missing.end());

        return missing + s;
    }
};
//https://leetcode.com/problems/shortest-palindrome/

//https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm