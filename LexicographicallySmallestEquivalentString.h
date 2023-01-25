class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> chars (26);
        for(int i=0; i<26; i++)
            chars[i] = 'a'+i;
        
        char from, to;
        for(int i=0; i<s1.size(); i++) {
            from = max(chars[s1[i]-'a'], chars[s2[i]-'a']);
            to = min(chars[s1[i]-'a'], chars[s2[i]-'a']);
 
            for(int j=0; j<26; j++)
                if(chars[j] == from)
                    chars[j] = to;
        }

        for(auto &c : baseStr)
            c = chars[c-'a'];

        return baseStr;
    }
};
//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/