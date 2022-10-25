class Solution {
public:
    string minWindow(string s, string t) {
        map<int, int> m;
        for(const auto &c : t) m[c]++;
        
        int count = t.size(), start = 0, end = 0, d = INT_MAX, head = 0;
        while(end<s.size()) {
            if((m[s[end++]]--) > 0) count--;
            
            while(count == 0) {
                if(end - start < d) 
                    d = end - (head = start);
                if(m[s[start++]]++ == 0)
                    count++;
            }
        }
        
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
//https://leetcode.com/problems/minimum-window-substring/