class Solution {
public:
    bool isPalindrome(string s) {
        for(int left=0, right=s.size()-1; left<right; left++, right--) {
            while(!isalnum(s[left]) && left<right) left++;
            while(!isalnum(s[right]) && left<right) right--;
            
            if(tolower(s[left]) != tolower(s[right]))
                return false;
        }
        return true;
    }
};
//https://leetcode.com/problems/valid-palindrome/

/* first attempt, cleaning the string than checking for palindrome (a lot slower) 
class Solution {

void clean(string &s) {
    int c;
    for(int i=0; i<s.size(); i++) {
        c = s[i]; 
        if(c >= 97 && c <= 122 || c >= 48 && c<= 57)
            continue;
        if(c >= 65 && c <= 90)
            s[i] = c+32;
        else 
            s.erase(s.begin()+(i--));
    }
}

public:
    bool isPalindrome(string s) {
        clean(s);
        
        int left=0, right=s.size()-1;
        while(left < right) 
            if(s[left++] != s[right--])
                return false;
        
        return true;
    }
};
*/