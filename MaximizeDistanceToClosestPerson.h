class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_distance = 0, last_taken_seat = -1;
        
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 0) {
                continue;
            }

            if(last_taken_seat == -1)
                max_distance = i;
            else
                max_distance = max(max_distance, (i-last_taken_seat)/2);

            last_taken_seat = i;
        }

        max_distance = max(max_distance, (int)seats.size() - 1 - last_taken_seat);
        return max_distance;
    }
};
//https://leetcode.com/problems/maximize-distance-to-closest-person/

/* 
first approach, passed all TC as well

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> taken = {0};
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 1) {
                taken.push_back(i);
            }
        }
        taken.push_back(seats.size()-1);

        int distance, max_distance = 0;
        for(int i = 1; i < taken.size(); i++) {
            if(i == 1)
                distance = taken[i];
            else if(i == taken.size()-1)
                distance = taken[i]-taken[i-1];
            else 
                distance = (taken[i]-taken[i-1]) / 2; 
            
            if(max_distance < distance) 
                max_distance = distance;
        }

        return max_distance;
    }
};

*/