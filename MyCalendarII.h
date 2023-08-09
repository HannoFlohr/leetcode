class MyCalendarTwo {
private:
    map<int,int> times;
public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        times[start]++;
        times[end]--;

        int current_bookings = 0;
        for(auto it = times.begin(); it != times.end(); ++it) {
            current_bookings += it->second;

            if(current_bookings == 3) {
                times[start]--;
                times[end]++;
                return false;
            }

            if(it->first > end)
                break;
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
 
 //https://leetcode.com/problems/my-calendar-ii/