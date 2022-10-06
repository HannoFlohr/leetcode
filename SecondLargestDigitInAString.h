class Solution {
public:
    int secondHighest(string s) {
        int largest = -1, second = -1, c;
        
        for(int i=0; i<s.size(); i++) {
            c = s[i]-'0';
            if(c>9) continue;
            
            if(largest < c) {
                second = largest;
                largest = c;
            }
            else if(largest != c && second < c) 
                second = c;
        }
        
        return second;
    }
};
//https://leetcode.com/problems/second-largest-digit-in-a-string/