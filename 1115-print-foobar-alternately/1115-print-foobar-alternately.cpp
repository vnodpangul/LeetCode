class FooBar {
private:
    int n;
    mutex _mtx;
    condition_variable _condAB, _condBA;
    bool done;
    int curr_A, curr_B;

public:
    FooBar(int n) {
        this->n = n;
        done = false;
        curr_A = 0, curr_B=0;
    }

    void foo(function<void()> printFoo) {
        
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(_mtx);
            _condAB.wait(lock, [this](){
               return !done; 
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            done = true;
            _condBA.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(_mtx);
            _condBA.wait(lock, [this](){
               return done; 
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            done = false;
            _condAB.notify_all();
        }
    }
};