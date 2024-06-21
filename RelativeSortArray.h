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
        for(auto it : frequency) {
            while(it.second > 0) {
                result.push_back(it.first);
                --it.second;
            }
        } 

        return result;
    }
};
//https://leetcode.com/problems/relative-sort-array/