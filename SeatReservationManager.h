class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> unreserved_seats;
    int max_reserved = 0;
public:
    SeatManager(int n) {}
    
    int reserve() {
        if(!unreserved_seats.empty()) {
            int new_reserved = unreserved_seats.top();
            unreserved_seats.pop();
            return new_reserved;
        }

        return ++max_reserved;
    }
    
    void unreserve(int seatNumber) {
        unreserved_seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
//https://leetcode.com/problems/seat-reservation-manager/

/*

class SeatManager {
private:
    set<int> free;
public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
            free.insert(i);
    }
    
    int reserve() {
        int new_reserve = *free.begin();
        free.erase(free.begin());
        return new_reserve;
    }
    
    void unreserve(int seatNumber) {
        free.insert(seatNumber);
    }
};

*/