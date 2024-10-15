class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i < arr.size(); ++i) 
            arr[i] ^= arr[i-1];
        
        vector<int> results (queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            if(queries[i][0] == 0)
                results[i] = arr[queries[i][1]];
            else
                results[i] = arr[queries[i][0]-1] ^ arr[queries[i][1]];

        }
        return results;
    }
};
//https://leetcode.com/problems/xor-queries-of-a-subarray/