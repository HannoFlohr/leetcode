class Solution {
public:
    int minimumPushes(string word) {
        //count frequency of each char and sort them
        vector<int> count_chars (26,0);
        for(char c : word) {
            ++count_chars[c-'a'];
        }
        sort(count_chars.rbegin(), count_chars.rend());

        //sum up needed pushes
        int min_pushes = 0;
        for(int letter = 0, pushes = 1; letter < 26; ++letter) {
            if(letter >= 8 && letter%8 == 0) {
                ++pushes;
            }
            min_pushes += count_chars[letter] * pushes;
        }

        return min_pushes;
    }
};
//https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/