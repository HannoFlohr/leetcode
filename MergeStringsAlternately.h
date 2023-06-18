class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int index = 0, size1 = word1.size(), size2 = word2.size();

        while(index < size1 || index < size2) {
            if(index < size1)
                merged += word1[index];
            if(index < size2)
                merged += word2[index];

            index++;
        }

        return merged;
    }
};
//https://leetcode.com/problems/merge-strings-alternately/