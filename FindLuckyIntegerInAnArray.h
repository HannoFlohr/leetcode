class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> frequency;
        for(int x : arr) {
            frequency[x]++;
        }

        for(auto it = frequency.rbegin(); it != frequency.rend(); it++) {
            if(it->first == it->second) {
                return it->first;
            }
        }

        return -1;
    }
};
//https://leetcode.com/problems/find-lucky-integer-in-an-array/