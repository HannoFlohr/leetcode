class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0, last_m = 0, last_p = 0, last_g = 0;

        for(int i = 0; i < garbage.size(); i++) {
            time += garbage[i].size();
            for(char c : garbage[i]) {
                if(c == 'M')
                    last_m = i;
                else if(c == 'P')
                    last_p = i;
                else
                    last_g = i;
            }
        }

        for(int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i-1];
        }

        if(last_m > 0)
            time += travel[last_m-1];
        if(last_g > 0)
            time += travel[last_g-1];
        if(last_p > 0)
            time += travel[last_p-1];

        return time;
    }
};
//https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

/* 
loop though all garbage
- time to pick up = 1 so just increment by size of garbage[i]
- and keep track of last occurrence of each m, p and g

sum up the travel time to get the total time to travel to each house
if last occurrence of each of m, p and/or g add the total travel time for them 

all TC passed 99%/14%

--
below: first approach using maps, all TC passed 5%/5%

class Solution {
private:
    int howLongToCollectAll(const map<int,int>& m, const vector<int>& travel) {
        int time = 0, truck_pos = 0;

        for(auto [house,amount] : m) {
            while(truck_pos < house) {
                time += travel[truck_pos];
                ++truck_pos;
            }
            time += amount;
        }

        return time;
    }
public:
    int garbageCollection(const vector<string>& garbage, const vector<int>& travel) {
        const int n = garbage.size();
        map<int,int> m, p, g;

        for(int i = 0; i < n; i++) {
            for(char c : garbage[i]) {
                if(c == 'M')
                    ++m[i];
                else if(c == 'P')
                    ++p[i];
                else
                    ++g[i];
            }
        }

        return howLongToCollectAll(m, travel) + howLongToCollectAll(p, travel) + howLongToCollectAll(g, travel);
    }
};
*/