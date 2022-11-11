class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for(auto &n : nums) {
            result.push_back(n);
            
            while(result.size() > 1 &&  gcd(result.back(), result[result.size()-2]) > 1) {
                int a = result.back(), b = result[result.size()-2];
                
                result.pop_back();
                result.pop_back();
                result.push_back( lcm(a,b) );
            }
        }   
        
        return result;
    }
};
//https://leetcode.com/problems/replace-non-coprime-numbers-in-array/submissions/