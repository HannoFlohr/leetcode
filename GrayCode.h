class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result (1<<n,0); 
        for(int i=0; i<(1<<n); i++)
            result[i] = i ^ (i>>1);
        return result;
    }
};
//https://leetcode.com/problems/gray-code/

//https://en.wikipedia.org/wiki/Gray_code