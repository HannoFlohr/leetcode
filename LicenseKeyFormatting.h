class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;
        
        for(auto c = s.rbegin(); c<s.rend(); c++){
            if(*c == '-') continue;
            if(result.size() % (k+1) == k) result += '-';
            result += toupper(*c);
        }

        reverse(begin(result), end(result));
        return result;
    }
};
//https://leetcode.com/problems/license-key-formatting/

/*
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        s.erase(remove(begin(s), end(s), '-'), end(s));
        for(auto &c : s) c = toupper(c);

        for(int pos = k; pos < s.size(); pos += 1 + k) 
            s.insert(s.end()-pos, 1, '-');
        return s;
    }
};
*/