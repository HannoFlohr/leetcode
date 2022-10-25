class Solution {
private:
    vector<string> less_than_20 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> less_than_100 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string make_string(int n) {
        if     (n >= 1000000000) return make_string(n/1000000000) + " Billion" + make_string(n - 1000000000 * (n/1000000000));
        else if(n >= 1000000)    return make_string(n/1000000) + " Million" + make_string(n - 1000000 * (n/1000000));
        else if(n >= 1000)       return make_string(n/1000) + " Thousand" + make_string(n - 1000 * (n/1000));
        else if(n >= 100)        return make_string(n/100) + " Hundred" + make_string(n - 100 * (n/100));
        else if(n >= 20)         return " " + less_than_100[n/10 - 2] + make_string(n - 10 * (n/10)); 
        else if(n >= 1)          return " " + less_than_20[n];
        else return "";
    }
    
public:
    string numberToWords(int num) {
        if(num == 0) return less_than_20[0];
        else return make_string(num).substr(1); 
    }
};
//https://leetcode.com/problems/integer-to-english-words/