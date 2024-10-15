class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetFriendArrivalTime = times[targetFriend][0], nextSeat = 0;
        set<int> emptySeats;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        sort(times.begin(), times.end());

        for(auto time : times) {
            int arrival = time[0], leaving = time[1], curSeat;

            //remove all leaving times in the queue that are <= current arrival time
            //and mark seat as empty
            while(!q.empty() && q.top().first <= arrival) {
                emptySeats.insert(q.top().second);
                q.pop();
            }

            //if there are empty seats take the first one
            if(!emptySeats.empty()) {
                curSeat = *emptySeats.begin();
                emptySeats.erase(emptySeats.begin());
            }
            //else take a new seat
            else {
                curSeat = nextSeat;
                ++nextSeat;
            }
            //add the current seat and leaving time to the queue
            q.push({leaving, curSeat});

            //check for target friend
            if(arrival == targetFriendArrivalTime) 
                return curSeat;
        }

        return 0;
    }
};
//https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/