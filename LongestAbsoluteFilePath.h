class Solution {
public:
    int lengthLongestPath(string input) {
        int level = 0, length = 0, max_length = 0;
        bool is_file = false;
        vector<int> lengths (1,0);

        for(char c : input) {
            switch(c) {
                case '\n' : {
                    level = 0;
                    length = 0; 
                    is_file = false;
                    break;
                }
                case '\t' : {
                    ++level;
                    break;
                }
                case '.' : 
                    is_file = true;
                default : {
                    ++length;
                    if(lengths.size() == level) {
                        lengths.emplace_back(0);
                    }
                    lengths[level] = length;
                    if(is_file) {
                        max_length = max(max_length, accumulate(lengths.begin(), lengths.begin()+level+1, 0) + level);
                    }
                }
            }
        }

        return max_length;
    }
};
//https://leetcode.com/problems/longest-absolute-file-path/