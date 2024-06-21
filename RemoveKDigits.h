class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) {
            return "0";
        }

        string result = num.substr(0,1);

        for(int i = 1; i < num.size(); ++i) {
            while(k > 0 && result.size() != 0 && num[i] < result.back()) {
                result.pop_back();
                --k;
            }

            //don't add preceding zeroes
            if(result.size() == 0 && num[i] == '0') {
                continue;
            }

            result.push_back(num[i]);
        }

        //remove last digits, while not enough were removed (k > 0)
        //happens for cases like 11234, i.e. last digits always larger than preceeding
        while(k > 0 && !result.size() == 0) {
            result.pop_back();
            --k;
        }
        
        return result == "" ? "0" : result;
    }
};
//https://leetcode.com/problems/remove-k-digits/

/* first approach: works for smaller 'num', but overflows for larger 'num', not even long long int are enough

class Solution {
private:
    void findSmallest(const string& num, int index, int k, int number, int& smallest) {
        if(index >= num.size()) {
            if(k == 0) {
                smallest = min(smallest, number);
            }
            return;
        }

        //try remove current
        if(k > 0) {
            findSmallest(num, index+1, k-1, number, smallest);
        }
        //try take current
        number = number*10 + (num[index]-'0');
        findSmallest(num, index+1, k, number, smallest);
    }

public:
    string removeKdigits(string num, int k) {
        int smallest = INT_MAX;
        findSmallest(num, 0, k, 0, smallest);
        return to_string(smallest);
    }
};
*/