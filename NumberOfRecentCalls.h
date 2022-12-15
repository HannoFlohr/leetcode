class RecentCounter {
private:
    const int RANGE = 3000;
    queue<int> calls;
public:
    RecentCounter() {}
    
    int ping(int t) {
        calls.push(t);
        while(calls.front() < t-RANGE) 
            calls.pop();
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
 
 //https://leetcode.com/problems/number-of-recent-calls/