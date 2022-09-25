class FrontMiddleBackQueue {
private:
    vector<int> fmbq;
    
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        fmbq.insert(fmbq.begin(), val);
    }
    
    void pushMiddle(int val) {
        fmbq.insert(fmbq.begin()+fmbq.size()/2, val);
    }
    
    void pushBack(int val) {
        fmbq.push_back(val);
    }
    
    int popFront() {
        if(fmbq.size() == 0) return -1;
        int val = fmbq[0];
        fmbq.erase(fmbq.begin());
        return val;
    }
    
    int popMiddle() {
        if(fmbq.size() == 0) return -1;
        int val = fmbq[(fmbq.size()-1)/2];
        fmbq.erase(fmbq.begin() + (fmbq.size()-1)/2);
        return val;
    }
    
    int popBack() {
        if(fmbq.size() == 0) return -1;
        int val = fmbq[fmbq.size()-1];
        fmbq.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
 
//https://leetcode.com/problems/design-front-middle-back-queue/