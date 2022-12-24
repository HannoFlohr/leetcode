class Solution {
private: 
    const enum COLORS_ENUM {
        RED = -1,
        GRAY = 0,
        BLUE = 1,
    };

    bool tryColoring(const int& person, const int& color, vector<vector<int>>& relations, vector<int>& colors) {
        //set color of current person
		colors[person] = color;

		//try drawing all other persons, that the current person dislikes, with the opposite color
        for(auto &other : relations[person]) {
			//other person has same color
            if(colors[other] == color)
                return false;
			//other person can not be colored differently 
            if(colors[other] == GRAY && (!tryColoring(other, -color, relations, colors)))
                return false;
        }

        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n == 1 || dislikes.size() == 0) return true;

        vector<vector<int>> relations (n+1);
        vector<int> colors (n+1, 0);

		//set relations for each person not liking others
        for(auto &d : dislikes) {
            relations[d[0]].emplace_back(d[1]);
            relations[d[1]].emplace_back(d[0]);
        }

		//check for each person if a bipartitioning is possible using a coloring scheme
        for(int person = 1; person <= n; person++) 
            if(colors[person] == GRAY && (!tryColoring(person, BLUE, relations, colors))) 
                return false;

        return true;
    }
};
//https://leetcode.com/problems/possible-bipartition/