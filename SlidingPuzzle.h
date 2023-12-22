class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const string goal_state = "123450";
        const vector<vector<int>> move_to {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};

        //start state as string
        string cur_state = "";
        for(vector<int>& row : board) {
            for(int col : row) {
                cur_state += to_string(col);
            }
        } 
    
        //bfs using a queue with current state and moves
        queue<pair<string,int>> q; //<state/moves>
        q.push({cur_state,0});
        unordered_set<string> visited;
        visited.insert(cur_state);
        int moves, zero_index;
        while(!q.empty()) {
            cur_state = q.front().first, moves = q.front().second;
            q.pop();

            if(cur_state == goal_state) { //end state encountered
                return moves;
            }

            zero_index = cur_state.find('0');

            //move to next states
            for(int from_index : move_to[zero_index]) {
                string next_state = cur_state;
                swap(next_state[from_index], next_state[zero_index]);

                if(visited.find(next_state) == visited.end()) {
                    visited.insert(next_state);
                    q.push({next_state, moves+1});
                }
            }
        }
    
        return -1;
    }
};
//https://leetcode.com/problems/sliding-puzzle/