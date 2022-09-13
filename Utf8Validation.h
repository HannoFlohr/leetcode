class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int check = 0;
        
        for(auto d:data) {
            if(check==0) {
                if(d/32 == 0b110) check = 1;
                else if(d/16 == 0b1110) check = 2; 
                else if(d/8 == 0b11110) check = 3;
                else if(d/128) return false;
            }
            else {
                if(d/64 != 0b10) return false;
                check--;
            }
        }
        
        return check==0;
    }
};
//https://leetcode.com/problems/utf-8-validation/