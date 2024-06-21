class Solution {
public:
    string smallestNumber(string pattern) {
        int size = pattern.size()+1, cur = 1, d_skipped = 0;
        string result = string(size, 'x');
        vector<int> reserved;

        //fill in lowest possible values for the increments and reserve skipped values for decrements
        for(int i = 0; i < pattern.size(); ++i) {
            if(pattern[i] == 'I') {
                result[i] = cur+'0';
                int next = cur+d_skipped+1;
                //if decrements were skipped, reserve 'd_skipped' values after cur for later
                while(d_skipped > 0) {
                    reserved.push_back(cur+d_skipped);
                    --d_skipped;; 
                }
                cur = next;
            }
            else { //remember skipped decrements
                ++d_skipped;
            }   
        }
        //add remaining values to the reserved values for decrements
        while(size >= cur) {
            reserved.push_back(size--);
        }
        //fill decrements
        for(int i = 0, r_index = 0; i < result.size(); ++i) {
            if(result[i] == 'x') {
                result[i] = reserved[r_index]+'0';
                ++r_index;
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/construct-smallest-number-from-di-string/