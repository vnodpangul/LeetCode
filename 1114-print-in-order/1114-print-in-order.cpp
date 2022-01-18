class Foo {
    
private:
     bool firstPrinted, secPrinted, thirdPrinted;
     mutex _mtx;
     condition_variable _cond;
public:
    Foo() {
        firstPrinted = false;
        secPrinted = false;
        thirdPrinted = false;
    }

    void first(function<void()> printFirst) {
        
        unique_lock<mutex> lock(_mtx);
         _cond.wait(lock, [this](){
             return (!firstPrinted);
         });

        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstPrinted = true;
        _cond.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(_mtx);
         _cond.wait(lock, [this](){
             return (firstPrinted);
         });
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secPrinted = true;
        _cond.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(_mtx);
         _cond.wait(lock, [this](){
             return (firstPrinted && secPrinted);
         });
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        thirdPrinted = true;
        _cond.notify_all();
    }
};