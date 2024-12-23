class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        int n = number.size();
        
        for(int i = 0; i < n; ++i) {
            //a '9' never gets swapped
            if(number[i] == 9)
                continue;
            //find max digit higher than digit at i from back
            int index = -1, higher_digit = number[i];
            for(int j = n-1; j > i; --j) {
                if(number[j] > higher_digit) {
                    higher_digit = number[j];
                    index = j;
                }
            }
            //if such a higher digit exists: swap the two
            if(index != -1) {
                swap(number[i], number[index]);
                break;
            }
        }
        

        return stoi(number);
    }
};
//https://leetcode.com/problems/maximum-swap/