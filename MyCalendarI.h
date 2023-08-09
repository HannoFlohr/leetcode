class MyCalendar {
private:
    set<pair<int,int>> times;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto timeslot = times.lower_bound({start, end});
        
        if( (timeslot != times.end() && !(timeslot->first >= end)) || 
            (timeslot != times.begin() && !(prev(timeslot)->second <= start)) )
            return false;

        times.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 
 //https://leetcode.com/problems/my-calendar-i/