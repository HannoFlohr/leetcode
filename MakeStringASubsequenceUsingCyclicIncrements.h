class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int index1 = 0, index2 = 0;

        while(index1 < str1.size() && index2 < str2.size()) {
            if(str1[index1] == str2[index2] || str1[index1]+1 == str2[index2] || str1[index1]-25 == str2[index2]) 
                ++index2;

            ++index1;
        }

        return index2 == str2.size();
    }
};
//https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/