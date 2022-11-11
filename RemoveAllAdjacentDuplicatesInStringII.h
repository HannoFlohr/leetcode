class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> chars = {{'#',0}}; //dummy entry to make stack non-empty
        
        for(auto &c : s) {
            if(chars.back().first != c) 
                chars.push_back({c,1});
            else if(++chars.back().second == k)
                chars.pop_back();     
        }
        
        string result;
        for(auto &c : chars) 
            result.append(c.second, c.first);
        
        return result;
    }
};
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/