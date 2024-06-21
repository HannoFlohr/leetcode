class Solution {
private:
    int findRotateSteps(const string& ring, const string& key, int key_index, int ring_position, 
                    unordered_map<char, vector<int>>& positions, vector<vector<int>>& distances) {
        //reached end of key?
        if(key_index == key.size()) {
            return 0;
        }
        //distance already computed?
        if(distances[key_index][ring_position] != -1) {
            return distances[key_index][ring_position];
        }

        int distance, distance_after, min_distance = INT_MAX;
        //for each possible ring position for the char at key_index 
        for(int next_position : positions[key[key_index]]) {
            //compute min distance from current ring position to that possible position
            if(next_position >= ring_position) {
                distance = min(next_position - ring_position, static_cast<int>(ring_position + ring.size()) - next_position);
            }
            else {
                distance = min(ring_position - next_position, static_cast<int>(next_position + ring.size()) - ring_position);
            }
            //compute min distances for chars after current key_index
            distance_after = findRotateSteps(ring, key, key_index+1, next_position, positions, distances);
            //update min distance accordingly
            min_distance = min(min_distance, distance + distance_after);
        }
        //remember min distance for jump from char at current ring position to char at key index
        return distances[key_index][ring_position] = min_distance + 1;
    }

public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> distances (key.size(), vector<int>(ring.size(), -1));
        unordered_map<char, vector<int>> positions;
        for(int i = 0; i < ring.size(); ++i) {
            positions[ring[i]].push_back(i);
        }
        return findRotateSteps(ring, key, 0, 0, positions, distances);
    }
};
//https://leetcode.com/problems/freedom-trail/