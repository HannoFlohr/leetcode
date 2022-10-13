class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first=-1, second=-1, countFirst=0, countSecond=0;
        
        for(auto &n : nums) {
            if(n == first) 
                countFirst++;
            else if(n == second) 
                countSecond++;
            else if(countFirst == 0) 
                first = n, countFirst++;
            else if(countSecond == 0)
                second = n, countSecond++;
            else
                countFirst--, countSecond--;
        }
        
        countFirst = countSecond = 0;
        for(auto &n : nums) {
            if(n == first) countFirst++;
            else if(n == second) countSecond++;
        }
        
        vector<int> result;
        if(countFirst > nums.size()/3) result.push_back(first);
        if(countSecond > nums.size()/3) result.push_back(second);
        
        return result;
    }
};
//https://leetcode.com/problems/majority-element-ii/

//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
//https://www.cs.rug.nl/~wim/pub/whh348.pdf