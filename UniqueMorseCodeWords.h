class Solution {
    
const vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; 
    
public:   
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> codes;
        string code;
        
        for(auto w:words) {
            code = "";
            for(auto c:w)
                code += morse[c - 'a'];
            
            codes.insert(code);
        }
        
        return codes.size();
    }
};
//https://leetcode.com/problems/unique-morse-code-words/