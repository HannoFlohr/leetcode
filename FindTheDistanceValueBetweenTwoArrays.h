class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int counter = arr1.size();
        for(auto &a : arr1) 
            for(auto &b : arr2) 
                if(abs(a-b) <= d) {
                    counter--;
                    break;
                }
        return counter;
    }
};
//https://leetcode.com/problems/find-the-distance-value-between-two-arrays/