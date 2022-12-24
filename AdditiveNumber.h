class Solution {
    bool isValid(string first, string second, string remaining) {
        if(first.size() > 1 && first[0] == '0' || second.size() > 1 && second[0] == '0')
            return false;

        string sum = to_string(stol(first) + stol(second));
        if(sum == remaining) 
            return true;
        if(remaining.size() <= sum.size() || sum.compare(remaining.substr(0, sum.size())) != 0)
            return false;
        else
            return isValid(second, sum, remaining.substr(sum.size()));
    }

public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; i++)
            for(int j = 1; j <= (num.size()-i)/2; j++)
                if(isValid(num.substr(0,i), num.substr(i,j), num.substr(i+j)))
                    return true;
        return false;
    }
};
//https://leetcode.com/problems/additive-number/