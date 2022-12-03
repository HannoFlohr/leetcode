class Solution {
public:
    string sortSentence(string s) {
        vector<string> words (9, "");
        
        stringstream ss (s);
        string cur;
        while(ss >> cur) 
            words[cur[cur.size()-1]-'0'-1] = cur.substr(0, cur.size()-1);
        
        s = "";
        for(auto &w : words) {
            if(w == "") break;
            s += w + " ";
        }
        
        return s.substr(0, s.size()-1);
    }
};
//https://leetcode.com/problems/sorting-the-sentence/