class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        vector<int> start_indices, chars_s (26,0), chars_p (26,0);
        const int n = p.size();

        for(int i=0; i<n; i++) {
            chars_p[p[i]-'a']++;
            chars_s[s[i]-'a']++;
        }
    	if(chars_p == chars_s) start_indices.push_back(0);

        for(int i=n; i<s.size(); i++) { 
            chars_s[s[i-n]-'a']--;
            chars_s[s[i]-'a']++;

            if(chars_p == chars_s) start_indices.push_back(i-n+1);
        }

        return start_indices;
    }
};
//https://leetcode.com/problems/find-all-anagrams-in-a-string/