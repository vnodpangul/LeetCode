// https://leetcode.com/problems/print-zero-even-odd/discuss/757773/C%2B%2B-48-ms6.9-MB-using-std%3A%3Acondition_variable-with-three-boolean-flags

class ZeroEvenOdd {
private:
    int n;
    mutex _mtx;
    condition_variable _cond;
    bool zeroTurn, oddTurn, evenTurn;
    int num=1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        // Turns done by the following types of numbers
        zeroTurn = false;
        oddTurn = false;
        evenTurn = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0; i<n; i++) {
            {
                    unique_lock<mutex> lock(_mtx);
                    _cond.wait(lock, [this](){
                        return !zeroTurn && (oddTurn || evenTurn) ;
                    });

            }
            printNumber(0);
            {
                lock_guard<mutex> _lg(_mtx);
                zeroTurn = true;
            }

            _cond.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1; i<=n; i+=2)  {
            {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this](){
                return zeroTurn && !oddTurn && evenTurn;
            });
            }

            printNumber(i);
            {
                lock_guard<mutex> _lg(_mtx);
                zeroTurn = false;
                oddTurn = true;
                evenTurn = false;
            }
            
            _cond.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
       for(int i=2; i<=n; i+=2) {
           {
            unique_lock<mutex> lock(_mtx);
            _cond.wait(lock, [this](){
                return zeroTurn && oddTurn && !evenTurn;
            });
           }
            printNumber(i); 
           {
                lock_guard<mutex> _lg(_mtx);
                zeroTurn = false;
                oddTurn = false;
                evenTurn = true;
            }

            _cond.notify_all();
        }
    }
};