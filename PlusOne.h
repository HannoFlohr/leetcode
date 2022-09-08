class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while(i >= 0 && digits[i] == 9)
            i--;
        
        if(i<0) {
            digits[0] = 1;
            digits.push_back(0);
            i = 1;
        }
        else {
            digits[i]++;
            i++;
        }
        
        for( ; i<digits.size(); i++)
            digits[i] = 0;
            
        return digits;
    }
};
//https://leetcode.com/problems/plus-one/

/* alternative solution, similar rumtime/space

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--) {
            if(digits[i] == 9) 
                digits[i] = 0; 
            else {
                digits[i]++;
                return digits;
            }
        }
        
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

*/