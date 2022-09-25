struct Node {
public:
    int val;
    Node* next;
    Node(int v, Node* n = NULL) : val(v), next(n) {};
};

class MyCircularQueue {
private:
    int max_size, size = 0;
    Node *head = new Node(0), *tail = new Node(0);
    
public:
    MyCircularQueue(int k) {
        max_size = k;
    }
    
    bool enQueue(int value) {
        if( isFull() ) return false;
        
        Node* node = new Node(value);
        
        if( isEmpty() ) head = node, tail = node;
        else tail->next = node, tail = tail->next;
        size++;
        
        return true;
    }
    
    bool deQueue() {
        if( isEmpty() ) return false;
        
        Node* node = head;
        head = head->next;
        delete node;
        size--;
        
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : head->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
 
 //https://leetcode.com/problems/design-circular-queue/