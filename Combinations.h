class Solution {
private: 
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> v (k, 0);
        int i=0;
        
        while(i >= 0) {
            v[i]++;
            
            //move index left if value is > n
            if(v[i] > n) i--;
            //add valid combination
            else if(i == k-1) combinations.push_back(v);
            //move index right and set value 
            else {
                i++;
                v[i] = v[i-1];
            }
        }
        
        return combinations;
    }
};
//https://leetcode.com/problems/combinations/