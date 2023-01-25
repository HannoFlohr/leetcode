class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = 0;
        while(index < letters.size() && letters[index] <= target)
            index++;
        return index == letters.size() ? letters[0] : letters[index];
    }
};
//https://leetcode.com/problems/find-smallest-letter-greater-than-target/