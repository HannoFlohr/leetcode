class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> result;
        int start, end;

        for(const string& word : words) {
            start = 0, end = 0;
            while(start < word.length()) {
                while(end < word.length() && word[end] != separator) {
                    end++;
                }
                if(end != start) {
                    result.push_back(word.substr(start, end-start));
                }
                end++;
                start = end;
            } 
        }

        return result;
    }
};
//https://leetcode.com/problems/split-strings-by-separator/