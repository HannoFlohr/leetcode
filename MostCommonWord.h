class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> words;
        string word = "";
        for(char c : paragraph) {
            if(isupper(c))
                c = tolower(c);
            if(isalpha(c)) {
                word += c;
                continue;
            }
            if(word == "")
                continue;

            words[word]++;
            word = "";
        }
        if(word != "")
            words[word]++; 

        for(string word : banned)
            words[word] = 0;

        int max_count = 0;
        for(auto [w,count] : words) { 
            if(count > max_count) {
                max_count = count;
                word = w;
            }
        }

        return word;
    }
};
//https://leetcode.com/problems/most-common-word/