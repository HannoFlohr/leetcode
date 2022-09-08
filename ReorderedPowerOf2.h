class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        vector<string> powers;
        int power = 0, i = 0;
        string p;
        while(power <= 1e9) {
            power = pow(2, i);
            p = to_string(power); 
            sort(p.begin(), p.end());
            powers.push_back(p);
            i++;
        }
        
        for(auto p : powers)
            if(p == s)
                return true;
        
        return false;
    }
};
//https://leetcode.com/problems/reordered-power-of-2/