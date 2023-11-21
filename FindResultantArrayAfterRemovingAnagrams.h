class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string word, last_word = "";
        vector<string> result;

        for(int i = 0; i < words.size(); i++) {
            word = words[i];
            sort(word.begin(), word.end()); 

            if(word != last_word) {
                result.push_back(words[i]);
            } 

            last_word = word;
        }

        return result;
    }
};
//https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/