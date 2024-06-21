class Solution {
private:
    bool isViablePosition(vector<int>& position, int distance, int m) {
        int count = 1, last_placed = position[0];
        for(int i = 1; i < position.size(); ++i) {
            if(position[i] - last_placed >= distance) {
                count++;
                last_placed = position[i];
            }
            if(count == m) {
                return true;
            }
        }
        return false;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1, high = (position.back() - position[0]) / (m-1), mid, force = 1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(isViablePosition(position, mid, m)) {
                force = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return force;
    }
};
//https://leetcode.com/problems/magnetic-force-between-two-balls/