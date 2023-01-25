class Solution {
public:
    string digitSum(string s, int k) {
        string new_s;
        int sum;
        while(s.length() > k) {
            new_s = "";
            for(int i=0; i<s.size(); i+=k) {
                sum = 0;
                for(int j=0; j<k; j++) {
                    if(i+j >= s.size()) break; 
                    sum += s[i+j]-'0';
                }
                
                new_s += to_string(sum);
            }

            s = new_s;
        }

        return s;        
    }
};
//https://leetcode.com/problems/calculate-digit-sum-of-a-string/