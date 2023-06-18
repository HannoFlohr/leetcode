class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniors = 0;

        for(const auto& person : details) 
            if(person[11] >= '7' || (person[11] == '6' && person[12] > '0') ) 
                seniors++;

        return seniors;
    }
};
//https://leetcode.com/problems/number-of-senior-citizens/