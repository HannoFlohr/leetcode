class Solution {
private: 
    vector<string> getNeighborsOf(const string& code) {
        vector<string> neighbors;

        for(int wheel = 0; wheel < 4; ++wheel) {
            for(int change = -1; change <= 1; change += 2) {
                string neighbor = code;
                neighbor[wheel] = (((neighbor[wheel]-'0') + change + 10) % 10)+'0';
                neighbors.push_back(neighbor);
            }
        }

        return neighbors;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead (deadends.begin(), deadends.end());

        if(dead.find("0000") != dead.end()) {
            return -1;
        }

        queue<string> q ({"0000"});
        int steps = 0, qsize;

        while(!q.empty()) {
            qsize = q.size();
            
            while(qsize--) {
                string current = q.front();
                q.pop();

                if(current == target) {
                    return steps;
                }

                for(string& neighbor : getNeighborsOf(current)) {
                    if(dead.find(neighbor) != dead.end()) {
                        continue;
                    }
                    dead.insert(neighbor);
                    q.push(neighbor);
                }
            }

            ++steps;
        }

        return -1;
    }
};
//https://leetcode.com/problems/open-the-lock/