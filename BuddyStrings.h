class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        int pos1 = -1, pos2 = -1;
        unordered_set<char> chars;
        
        for(int i=0; i<s.size(); i++) {
            chars.insert(s[i]);
            
            if(s[i] == goal[i]) continue;
            
            if(pos1 == -1) pos1 = i;
            else if(pos2 == -1) pos2 = i;
            else return false; //third differing char found -> cant be converted by swapping 
        }
        
        if(pos1 != -1 && pos2 != -1) //two differing chars, check if positions can be swapped
            return s[pos1] == goal[pos2] && s[pos2] == goal[pos1];
        
        if(pos1 != -1)  
            return false; //only one differing char found 
        
        //no differing chars found, check if at least one duplicate letter exists
        return chars.size() < s.size();
    }
};
//https://leetcode.com/problems/buddy-strings/