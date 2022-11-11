class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int spaces = 0;
        string s = "";
        
        for(int i=0; i<text.size(); i++) {
            if(text[i] == ' ') spaces++;
            else {
                while(i < text.size() && text[i] != ' ') {
                    s += text[i];
                    i++;
                }
                words.push_back(s);
                s = "";
                i--;
            }
        }
        
        if(words.size() == 1) 
            return words[0] + string(spaces, ' ');
        
        int gap = spaces / (words.size() - 1); 
        for(auto &word : words) 
            s += word + string(gap, ' ');
        
        return s.substr(0, s.size() - gap) + string(spaces % (words.size()-1), ' ');
    }
};
//https://leetcode.com/problems/rearrange-spaces-between-words/