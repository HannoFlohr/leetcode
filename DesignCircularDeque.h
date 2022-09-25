class MyCircularDeque {
private:
    vector<int> deque;
    int size = 0, k, front, back = 0;
    
public:
    MyCircularDeque(int k) : deque(k,0), k(k), front(k-1) {}
    
    bool insertFront(int value) {
        if( isFull() ) return false;
        
        deque[front] = value;
        front = (front-1+k) % k;
        size++;
        
        return true;
    }
    
    bool insertLast(int value) {
        if( isFull() ) return false;
        
        deque[back] = value;
        back = (back+1) % k;
        size++;
        
        return true;
    }
    
    bool deleteFront() {
        if( isEmpty() ) return false;
        
        front = (front+1) % k;
        size--;
        
        return true;
    }
    
    bool deleteLast() {
        if( isEmpty() ) return false;
        
        back = (back-1+k) % k;
        size--;
        
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : deque[(front+1) % k];
    }
    
    int getRear() {
        return isEmpty() ? -1 : deque[(back-1+k) % k];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
 
 //https://leetcode.com/problems/design-circular-deque/