class Solution {

int set(string& s, string stamp) {
    for(int i=0; i<s.length(); i++) {
        int j=0, k=i;
        bool flag = false;
        while(j < stamp.length() && k < s.length() && (s[k]=='*' || s[k]==stamp[j])) {
            if(s[k] == stamp[j])
                flag = true;
            k++;
            j++;
        }
        if(j == stamp.length() && flag) {
            for(int l=0; l<stamp.length(); l++) 
                s[i + l] = '*';
            return i;
        }
    }
    return s.length();
}
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        string s = target;
        string s_init (target.length(), '*');
        
        vector<int> result;
        vector<int> valid;
        
        while(s != s_init) {
            int x = set(s, stamp);
            if(x == s.length()) 
                return result;
            valid.push_back(x);
        }
        
        for(int i=valid.size()-1; i>=0; i--) 
            result.push_back(valid[i]);
        
        return result;
    }
};
//https://leetcode.com/problems/stamping-the-sequence/submissions/