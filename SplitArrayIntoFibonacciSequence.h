class Solution {
private:
    bool fiboSeq(const string& s, int start, vector<int>& result) {
        if(start == s.size() && result.size() > 2) return true;

        int max_f_size = s[start]=='0' ? 1 : 10; 
        long number;
        for(int i=1; i <= max_f_size && start+i <= s.size(); i++) {
            number = stol(s.substr(start, i));

            if(number > INT_MAX) 
                return false;

            if(result.size() >= 2 && number > (long)result.back() + (long)result[result.size()-2])
                return false;
            if(result.size() < 2 || number == (long)result.back() + (long)result[result.size()-2]) {
                result.push_back(number);
                if(fiboSeq(s, start+i, result))
                    return true;
                result.pop_back();
            }
        }

        return false;
    }

public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> result;
        fiboSeq(num, 0, result);
        return result;
    }
};
//https://leetcode.com/problems/split-array-into-fibonacci-sequence/