class MyQueue {
private:
    stack<int> q_in, q_out;
    
    void fillOutput() {
        while(!q_in.empty()) {
            q_out.push(q_in.top());
            q_in.pop();
        }
    }
    
public:
    MyQueue() {}
    
    void push(int x) {
        q_in.push(x);
    }
    
    int pop() {
        int x = peek();
        q_out.pop();
        return x;
    }
    
    int peek() {
        if(q_out.empty()) fillOutput();
        return q_out.top();
    }
    
    bool empty() {
        return q_in.empty() && q_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 
 //https://leetcode.com/problems/implement-queue-using-stacks/