class Foo {
private:
    mutable mutex m;
    int action = 0;
    condition_variable cv;
    
public:
    Foo() {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    
        action++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        while(action < 1)
            cv.wait(lock);
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        action++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        while(action < 2)
            cv.wait(lock);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
//https://leetcode.com/problems/print-in-order/