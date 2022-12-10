class MinStack {
private:
    vector<int> my_stack;
    vector<int> my_min_values;
public:
    MinStack() {}
    
    void push(int val) {
        my_stack.push_back(val);
        if(my_min_values.empty() || val <= getMin())
            my_min_values.push_back(val);
    }
    
    void pop() {
        if(my_stack.back() == getMin()) 
            my_min_values.pop_back();
        my_stack.pop_back();
    }
    
    int top() {
        return my_stack.back();    
    }
    
    int getMin() {
        return my_min_values.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 //https://leetcode.com/problems/min-stack/