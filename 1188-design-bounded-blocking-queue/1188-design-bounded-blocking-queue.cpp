
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        _maxSize = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(_mtx);
        _notify_for_enque.wait(lock, [this](){
            return _q.size()<_maxSize;
        });
        
        _q.push_front(element);
        lock.unlock();
        _notify_for_deque.notify_one(); // Notify only one thread to avoid waking up all threads
    }
    
    int dequeue() {
        unique_lock<mutex> lock(_mtx);
        _notify_for_deque.wait(lock, [this](){
            return _q.size()>0;
        });
        int element = _q.back(); _q.pop_back();
        
        lock.unlock();
        _notify_for_enque.notify_one();
        return element; 
    }
    
    int size() {
        lock_guard<mutex> lock(_mtx);
        return _q.size();
    }
private:
    deque<int> _q;
    mutex _mtx;
    condition_variable _notify_for_deque, _notify_for_enque; // Use two condition variables to avoid starvation
    int _maxSize = 0;
};
