class MyCalendarThree {
private:
    map<int,int> times;
public:
    MyCalendarThree() {   
    }
    
    int book(int startTime, int endTime) {
        times[startTime]++;
        times[endTime]--;

        int k = 0, current = 0;
        for(const auto& [_,x] : times) {
            current += x;
            k = max(k, current);
        }

        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
 
 //https://leetcode.com/problems/my-calendar-iii/