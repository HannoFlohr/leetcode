class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        
        vector<pair<int,int>> walls;
        for(auto b:buildings) {
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());
        
        multiset<int> leftWall {0};
        int max_height = 0;
        for(auto w:walls) {
            if(w.second < 0)
                leftWall.insert(-w.second);
            else
                leftWall.erase(leftWall.find(w.second)); 
            
            if(*leftWall.rbegin() != max_height) {
                max_height = *leftWall.rbegin();
                result.push_back({w.first, max_height});
            }
        }
        
        return result;
    }
};
//https://leetcode.com/problems/the-skyline-problem/