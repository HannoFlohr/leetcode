class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_length = -1;
        vector<int> first_occurrece_of_char (26,-1);

        for(int i = 0; i < s.length(); i++) {
            if(first_occurrece_of_char[s[i]-'a'] == -1) {
                first_occurrece_of_char[s[i]-'a'] = i;
            }
            else {
                max_length = max(max_length, i - first_occurrece_of_char[s[i]-'a'] - 1);
            }
        }

        return max_length;
    }
};
//https://leetcode.com/problems/largest-substring-between-two-equal-characters/

/*
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,vector<int>> char_indices;
        for(int i = 0; i < s.length(); i++) {
            char_indices[s[i]].push_back(i);
        }

        int max_length = -1;
        for(auto& [_,indices] : char_indices) {
            if(indices.size() >= 2) {
                max_length = max(max_length, indices.back() - indices[0] - 1);
            }
        }

        return max_length;
    }
};
*