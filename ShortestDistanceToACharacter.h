class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length(), last_found = -n;
        vector<int> distances (n, 1e5);

        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                last_found = i;
            }
            distances[i] = i - last_found;
        }

        for(int i = last_found-1; i >= 0; i--) {
            if(s[i] == c) {
                last_found = i;
            }
            distances[i] = min(distances[i], last_found-i);

        }

        return distances;    
    }
};
//https://leetcode.com/problems/shortest-distance-to-a-character/