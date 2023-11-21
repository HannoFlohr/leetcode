class Solution {
public:
    string removeOccurrences(string s, string part) {
        const int partlength = part.length();
        int new_index = 0;
        string result = s;
        
        for(int i = 0; i < s.length(); ++i) {
            result[new_index++] = s[i];

            if(new_index >= partlength && result.substr(new_index-partlength, partlength) == part)
                new_index -= partlength;
        }

        return result.substr(0, new_index);
    }
};
//https://leetcode.com/problems/remove-all-occaurrences-of-a-substring/