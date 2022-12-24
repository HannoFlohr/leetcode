class KthLargest {
private: 
    int max_size;
    priority_queue<int, vector<int>, greater<int>> numbers;

public:
    KthLargest(int k, vector<int>& nums) {
        max_size = k;
        for(int &n : nums) {
            numbers.push(n);
            if(numbers.size() > max_size)
                numbers.pop(); 
        }
    }
    
    int add(int val) {
        numbers.push(val);
        if(numbers.size() > max_size)
            numbers.pop();
        return numbers.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
 //https://leetcode.com/problems/kth-largest-element-in-a-stream/