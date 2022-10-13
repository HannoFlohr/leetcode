class Solution {
private:
    const vector<unordered_set<char>> dict = {
            {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'},
            {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'},
            {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'}};

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        
        for(auto &word : words) {
            vector<bool> row (3, true);
            
            for(auto &c : word) 
                for(int i=0; i<3; i++) 
                    if(row[i] && dict[i].find(c) == dict[i].end())
                        row[i] = false;
            
            if(row[0] || row[1] || row[2])
                result.push_back(word);
        }
        
        return result;
    }
};
//https://leetcode.com/problems/keyboard-row/