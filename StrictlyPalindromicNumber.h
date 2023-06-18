class Solution {
private:
    //converts the decimal 'number' to its representation in base 'b' 
    string fromDecimal(int number, const int &base) {
        string result = "";
        int index = 0;
        while (number > 0) {
            result += ((number % base) + '0'); 
            number /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isPalindromic(const string& s) {
        int left = 0, right = s.size()-1;
        while(left < right) 
            if(s[left++] != s[right--])
                return false;
        return true;
    }

public:
    bool isStrictlyPalindromic(int n) {
        for(int base = 2; base <= n-2; ++base)
            if( !isPalindromic( fromDecimal(n,base) ) )
                return false;
        return true;
    }
};
//https://leetcode.com/problems/strictly-palindromic-number/