class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        int x = 0, y = 0;
        visited.insert({x,y});

        for(char c : path) {
            switch(c) {
                case 'N' : y++; break;
                case 'S' : y--; break;
                case 'E' : x++; break;
                case 'W' : x--; break;
            }

            if(visited.find({x,y}) != visited.end()) {
                return true;
            }

            visited.insert({x,y});
        }

        return false;
    }
};
//https://leetcode.com/problems/path-crossing/