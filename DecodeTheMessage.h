class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> decode (26, '.');
        int cur = 0;

        for(char c : key) {
            if(c == ' ' || decode[c-'a'] != '.') {
                continue;
            }
            decode[c-'a'] = cur+'a';
            cur++;
        }

        for(char& c : message) {
            if(c != ' ') {
                c = decode[c-'a'];   
            }
        }

        return message;
    }
};
//https://leetcode.com/problems/decode-the-message/