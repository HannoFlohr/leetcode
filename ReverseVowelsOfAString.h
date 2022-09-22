class Solution {
    
bool isVowel(char c) const {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
}
    
public:
    string reverseVowels(string s) {
        int left=0, right=s.size()-1;
        while(left<right) {
            while( !isVowel(s[left])  && left<right ) left++;
            while( !isVowel(s[right]) && left<right) right--;
            
            if(left<right) swap(s[left++], s[right--]);
        }
        
        return s;
    }
};
//https://leetcode.com/problems/reverse-vowels-of-a-string/