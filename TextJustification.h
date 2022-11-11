class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string s;
        int n = words.size();
        
        for(int i=0, last, width; i<n; i += last) {
            //find the last index that can be used for the current line
            for(last = width = 0; i + last < n && width + words[i+last].size() <= maxWidth - last; last++) 
                width += words[i+last].size();
            
            //for each line words[i] to words[i+last-1] can be used
            s = words[i];
            for(int j=0; j<last-1; j++) {
                if(i + last >= n) s += " ";
                else s += string((maxWidth - width) / (last - 1) + (j < (maxWidth - width) % (last - 1)), ' '); 
                s += words[i+j+1];
            }
            
            s += string(maxWidth - s.size(), ' ');
            result.push_back(s);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/text-justification/