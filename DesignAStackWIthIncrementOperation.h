class CustomStack {
private:
    vector<int> stack;
    int max_size;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < max_size)
            stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty())
            return -1;
        
        int value = stack.back();
        stack.pop_back();
        return value;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k,(int)stack.size()); ++i)
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
 
 //https://leetcode.com/problems/design-a-stack-with-increment-operation/