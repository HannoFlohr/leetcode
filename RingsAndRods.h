class Solution {
public:
    int countPoints(string rings) {
        vector<vector<bool>> rods (10, vector<bool>(3,false)); 
        for(int i = 0; i < rings.size()-1; ++i) {
            switch(rings[i]) {
                case 'R' : rods[rings[i+1]-'0'][0] = true; break;
                case 'G' : rods[rings[i+1]-'0'][1] = true; break;
                case 'B' : rods[rings[i+1]-'0'][2] = true; break;
            }
        }

        int has_all_colors = 0;
        for(vector<bool> rod : rods) {
            if(rod[0] && rod[1] && rod[2])
                ++has_all_colors;
        }

        return has_all_colors;
    }
};
//https://leetcode.com/problems/rings-and-rods/