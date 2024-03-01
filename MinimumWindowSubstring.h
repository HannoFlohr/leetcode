class Solution {
public:
    string minWindow(string s, string t) {
        int remaining = t.size(), start = 0, end = 0, min_distance = INT_MAX, start_of_result = 0;
        map<int, int> needed;

        for(char c : t) 
            needed[c]++;
        
        while(end < s.size()) {
            if((needed[s[end++]]--) > 0) 
                remaining--;
            
            while(remaining == 0) {
                if(end - start < min_distance) {
                    min_distance = end - start;
                    start_of_result = start;
                }
                if(needed[s[start++]]++ == 0)
                    remaining++;
            }
        }
        
        return min_distance == INT_MAX ? "" : s.substr(start_of_result, min_distance);
    }
};
//https://leetcode.com/problems/minimum-window-substring/