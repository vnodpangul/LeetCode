class FizzBuzz {
private:
    int n;
    int count=1;
    mutex _mtx;
    condition_variable _cond;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true) {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this]() {
                return ((count>n) || (count%3==0 && count%5 != 0));
            });
            if(count>n) {
                return;
            }
            
            printFizz();
            ++count;
            lock.unlock();
            _cond.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
         while(true) {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this]() {
                return ((count>n) || (count%3!=0 && count%5 == 0));
            });
            if(count>n) {
                return;
            }
            
            printBuzz();
            ++count;
            lock.unlock();
            _cond.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this]() {
                return ((count>n) || (count%3==0 && count%5==0));
            });
            if(count>n) {
                return;
            }
            
            printFizzBuzz();
            ++count;
            lock.unlock();
            _cond.notify_all();
        }

    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this]() {
                return ((count>n) || (count%3!=0 && count%5!=0));
            });
            if(count>n) {
                return;
            }
            
            printNumber(count);
            ++count;
            lock.unlock();
            _cond.notify_all();
        }
    }
};