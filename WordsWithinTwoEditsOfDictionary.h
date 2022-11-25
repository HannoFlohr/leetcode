class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int not_equal;
        
        for(string &q : queries) {
            for(string &d : dictionary) {
                not_equal = 0; 
                for(int i=0; i<d.size(); i++) { 
                    if(d[i] != q[i]) { 
                        not_equal++;
                        if(not_equal > 2)
                            break;        
                    }
                }
                
                if(not_equal <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }
        
        return result;
    }
};

//https://leetcode.com/problems/words-within-two-edits-of-dictionary/