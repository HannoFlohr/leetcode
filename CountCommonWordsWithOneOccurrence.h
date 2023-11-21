class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> count1, count2;
        for(string& word : words1) {
            count1[word]++;
        }
        for(string& word : words2) {
            count2[word]++;
        }

        int one_common_occurrence = 0;
        for(auto& [word,count] : count1) {
            if(count == 1 && count2[word] == 1) {
                one_common_occurrence++;
            }
        }

        return one_common_occurrence;
    }
};
//https://leetcode.com/problems/count-common-words-with-one-occurrence/