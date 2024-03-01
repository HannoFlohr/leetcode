class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> frequency;
        for(int x : arr1) {
            frequency[x]++;
        }

        vector<int> result;
        for(int x : arr2) {
            while(frequency[x] > 0) {
                result.push_back(x);
                frequency[x]--;
            }
        }
        for(auto& [x,f] : frequency) {
            while(f > 0) {
                result.push_back(x);
                f--;
            }
        } 

        return result;
    }
};
//https://leetcode.com/problems/relative-sort-array/