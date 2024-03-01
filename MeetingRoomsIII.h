bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compare);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        priority_queue<int, vector<int>, greater<int>> unused;
        unordered_map<int,int> frequency;

        for(int i = 0; i < n; ++i) {
            unused.push(i);
        }

        for(vector<int>& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
        
            while(used.size() > 0 && used.top().first <= start) {
                int room = used.top().second;
                used.pop();
                unused.push(room);
            } 

            if(unused.size() > 0) {
                int room = unused.top();
                unused.pop();
                frequency[abs(room)] += 1;
                used.push({end, room});
            }
            else {
                pair<long long, int> topused = used.top();
                used.pop();
                frequency[abs(topused.second)] += 1;

                long long new_end = topused.first;
                new_end += (end - start);

                used.push({new_end, topused.second});
            }
        
        }

        int max_index;
        for(int i= 1; i < n; ++i) {
            if(frequency[i] > frequency[max_index])
                max_index = i;
        }
        return max_index;
    }
};
//https://leetcode.com/problems/meeting-rooms-iii/