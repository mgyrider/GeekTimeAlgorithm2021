class MyCircularDeque {
private:
    int k;
    int *array;
    int front;
    int rear; 
    int curSize;
public:
    MyCircularDeque(int k) {
        this->k = k;
        this->array = new int[k + 1];
        this->front = 0;
        this->rear = 1;
        this->curSize = 0;
    }
    ~MyCircularDeque() {
        delete[] array;
    }
    
    bool insertFront(int value) {
        if (curSize == k) {
            return false;
        }
        array[front] = value;
        front--;
        if (front < 0) {
            front = k;
        }
        ++curSize;
        return true;
    }
    
    bool insertLast(int value) {
        if (curSize == k) {
            return false;
        }
        array[rear] = value;
        rear++;
        if (rear > k) {
            rear = 0;
        }
        ++curSize;
        return true;
    }
    
    bool deleteFront() {
        if (curSize == 0) {
            return false;
        }
        front++;
        if (front > k) {
            front = 0;
        }
        --curSize;
        return true;
    }
    
    bool deleteLast() {
        if (curSize == 0) {
            return false;
        }
        rear--;
        if (rear < 0) {
            rear = k;
        }
        --curSize;
        return true;
    }
    
    int getFront() {
        if (curSize == 0) {
            return -1;
        }
        if (front + 1 > k) {
            return array[0];
        }
        return array[front + 1];
    }
    
    int getRear() {
        if (curSize == 0) {
            return -1;
        }
        if (rear - 1 < 0) {
            return array[k];
        }
        return array[rear - 1];
    }
    
    bool isEmpty() {
        return curSize == 0;
    }
    
    bool isFull() {
        return curSize == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */