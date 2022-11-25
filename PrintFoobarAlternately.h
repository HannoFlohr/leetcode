class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool isFoo = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(!isFoo) 
                cv.wait(lock);
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            isFoo = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(isFoo) 
                cv.wait(lock);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            isFoo = true;
            cv.notify_all();
        }
    }
};
//https://leetcode.com/problems/print-foobar-alternately/