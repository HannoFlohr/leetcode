class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> neighbors;

        for(auto pair : adjacentPairs) {
            neighbors[pair[0]].push_back(pair[1]);
            neighbors[pair[1]].push_back(pair[0]);
        }

        vector<int> arr;
        for(auto& [number, adjacent] : neighbors) {
            if(adjacent.size() == 1) {
                arr.push_back(number);
                arr.push_back(adjacent[0]);
                break;
            }
        }

        while(arr.size() < adjacentPairs.size()+1) {
            int last = arr.back(), previous = arr[arr.size() - 2];
            if(neighbors[last][0] != previous)
                arr.push_back(neighbors[last][0]);
            else
                arr.push_back(neighbors[last][1]);
        }

        return arr;
    }
};
//https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/