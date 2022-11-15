class MedianFinder {
private:
    priority_queue<int> lower_half, higher_half;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        lower_half.push(num);
        higher_half.push(-lower_half.top());
        lower_half.pop();
        if(lower_half.size() < higher_half.size()) {
            lower_half.push(-higher_half.top());
            higher_half.pop();
        }
    }
    
    double findMedian() {
        return lower_half.size() > higher_half.size() ? lower_half.top() : ((double)lower_half.top() - (double)higher_half.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
 //https://leetcode.com/problems/find-median-from-data-stream/