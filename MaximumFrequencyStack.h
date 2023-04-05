class FreqStack {
private:
    priority_queue<pair<int, pair<int,int>>> pq;
    unordered_map<int,int> frequency;
    int id = 0;

public:
    FreqStack() {}
    
    void push(int val) {
        frequency[val]++;
        id++;
        pq.emplace(frequency[val], make_pair(id, val));
    }
    
    int pop() {
        int val = pq.top().second.second;
        pq.pop();
        frequency[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
 
//https://leetcode.com/problems/maximum-frequency-stack/