class Solution {
private:
    int maximumRequests(int n, const vector<vector<int>>& requests, int index, vector<int>& buildings) {
        if(index == requests.size())
            return count(buildings.begin(), buildings.end(), 0) == n ? 0 : INT_MIN;
        
        buildings[requests[index][0]]--;
        buildings[requests[index][1]]++;
    
        int take_current = 1 + maximumRequests(n, requests, index+1, buildings);

        buildings[requests[index][0]]++;
        buildings[requests[index][1]]--;

        return max(take_current, maximumRequests(n, requests, index+1, buildings));
    }

public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> buildings (n, 0);
        return maximumRequests(n, requests, 0, buildings);
    }
};
//https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/