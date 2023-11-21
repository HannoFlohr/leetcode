class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss (sentence);
        string cur;
        int wordcount = 1;
        while(ss >> cur) {
            if(cur.find(searchWord) == 0)
                return wordcount;
            
            ++wordcount;
        }

        return -1;
    }
};
//https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto check = (' '+sentence).find(' '+searchWord);
        return check == string::npos ? -1 : count(sentence.begin(), sentence.begin()+check, ' ')+1;
    }
};