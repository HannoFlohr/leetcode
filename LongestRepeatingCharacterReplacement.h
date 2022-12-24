class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        vector<int> char_count (26, 0);
        int start = 0, max_char_count = 0, result = 0;

        for(int end = 0; end < n; end++) {
            char_count[s[end]-'A']++;
            if(max_char_count < char_count[s[end]-'A'])
                max_char_count = char_count[s[end]-'A'];

            while(end - start - max_char_count + 1 > k) {
                char_count[s[start]-'A']--;
                start++;
            }

            result = max(result, end - start + 1);
        }

        return result;
    }
};
//https://leetcode.com/problems/longest-repeating-character-replacement/