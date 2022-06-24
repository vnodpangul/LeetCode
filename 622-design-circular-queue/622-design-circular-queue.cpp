class MyCircularQueue {
    vector<int> q;
    int size, front, rear, currentSize;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
        front = rear = 0;
        currentSize = 0;
        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[rear] = value;
        rear = (rear+1)%size;
        currentSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front+1)%size;
        currentSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return rear-1 < 0 ? q[size-1] : q[rear-1];
    }
    
    bool isEmpty() {
        return currentSize==0;
    }
    
    bool isFull() {
        return currentSize == size;
    }
};

// size = k = 2
// front = 0 --> front+1%k -->  
// rear =  0-->1%2 -->3%2 = 0
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