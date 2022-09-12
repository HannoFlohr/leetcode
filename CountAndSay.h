class Solution {
public:
    string countAndSay(int n) {
        if(!n) return "";
        
        string s, result = "1";
        
        while(--n) {
            s = "";
            for(int i=0; i<result.size(); i++) {
                int count = 1;
                while(i+1 < result.size() && result[i]==result[i+1]) {
                    count++;
                    i++;
                }
                s += to_string(count) + result[i];
            }
            
            result = s;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/count-and-say/