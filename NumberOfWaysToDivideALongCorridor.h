class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9+7;
        vector<int> seats;
        
        for(int i = 0; i < corridor.size(); i++) {
            if(corridor[i] == 'S') {
                seats.push_back(i);
            }
        }

        if(seats.size() % 2 == 1 || seats.size() == 0) {
            return 0;
        }

        long count = 1;
        int previous = seats[1], gap;
        for(int i = 2; i < seats.size(); i += 2) {
            gap = seats[i] - previous;
            count = (count * gap) % MOD;
            previous = seats[i+1];
        }

        return (int)count;
    }
};
//https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/