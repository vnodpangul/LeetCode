class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        maxSize = k;
        arr.resize(maxSize, -1);
    }
    
    bool enQueue(int value) {
        if(size == maxSize) return false;
        
        arr[rear] = value;
        size++; rear = (rear+1)%maxSize;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        
        front = (front+1)%maxSize;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(size == 0) return -1;
        int idx = (rear-1) < 0 ?  maxSize-1 : (rear-1)%maxSize;
        return arr[idx];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==maxSize;
    }
private:
    int maxSize=0, size=0;
    vector<int> arr;
    int front=0, rear=0; 
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

// [ 1, 2, 3]   size = 3, maxSize =3
// i=(0+1+1)%maxSize front rear