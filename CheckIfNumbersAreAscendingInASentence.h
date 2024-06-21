class Solution {
public:
    bool areNumbersAscending(string s) {
        int last_number = -1, number;
        istringstream ss (s);
        string token;

        while(ss >> token) {
            if(token[0] < '0' || token[0] > '9') {
                continue;
            }

            number = stoi(token);
            if(number <= last_number) {
                return false;
            }
            last_number = number;
        }

        return true;
    }
};
//https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/