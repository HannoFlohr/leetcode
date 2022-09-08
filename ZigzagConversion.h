class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        vector<string> zigzag (numRows, "");
        for(unsigned i=0, row=0, direction=1; i<s.size(); i++) {
            zigzag[row] += s[i];
            
            if(row==0) direction = 1;
            if(row==numRows-1) direction = -1;
            row += direction;
        }
        
        string result = "";
        for(auto z:zigzag) result += z;
        
        return result;
    }
};
//https://leetcode.com/problems/zigzag-conversion/