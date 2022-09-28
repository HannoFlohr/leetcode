class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==-1) return false; //index already visited
        
        if(arr[start]==0) return true; //0 reached
        
        int left = start - arr[start], right = start + arr[start]; //jump targets
        arr[start] = -1; //mark as visited
        
        return (left >= 0 && canReach(arr, left)) || (right < arr.size() && canReach(arr, right));
    }
};
//https://leetcode.com/problems/jump-game-iii/