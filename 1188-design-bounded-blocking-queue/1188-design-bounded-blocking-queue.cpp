#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <deque>

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        _maxSize = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock, [this](){
            return _q.size()<_maxSize;
        });
        
        _q.push_front(element);
        lock.unlock();
        _cond.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock, [this](){
            return _q.size()>0;
        });
        int element = _q.back(); _q.pop_back();
        
        lock.unlock();
        _cond.notify_all();
        return element; 
    }
    
    int size() {
        return _q.size();
    }
private:
    deque<int> _q;
    mutex _mtx;
    condition_variable _cond;
    int _maxSize = 0;
};
