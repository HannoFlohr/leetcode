class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = -1, second = -1, count_first = 0, count_second = 0;
        
        for(int n : nums) {
            if(n == first) 
                count_first++;
            else if(n == second) 
                count_second++;
            else if(count_first == 0) 
                first = n, count_first++;
            else if(count_second == 0)
                second = n, count_second++;
            else
                count_first--, count_second--;
        }
        
        count_first = count_second = 0;
        for(int n : nums) {
            if(n == first) 
                count_first++;
            else if(n == second) 
                count_second++;
        }
        
        vector<int> result;
        if(count_first > nums.size()/3) 
            result.push_back(first);
        if(count_second > nums.size()/3) 
            result.push_back(second);
        
        return result;
    }
};
//https://leetcode.com/problems/majority-element-ii/

//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
//https://www.cs.rug.nl/~wim/pub/whh348.pdf