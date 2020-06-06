class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        nums.resize(k);
        size = 0;
        fi = -1; // point to the current front element
        bi = 0;  // point to the current back element
        this->k = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (!isFull()) {
            ++size;
            fi = (fi + 1) % k;
            nums[fi] = value;
            return true;
        } else {
            return false;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (!isFull()) {
            ++size;
            if (--bi < 0) bi += k;
            nums[bi] = value;
            return true;
        } else {
            return false;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (!isEmpty()) {
            --size;
            if(--fi < 0) fi += k;
            return true;
        } else {
            return false;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (!isEmpty()) {
            --size;
            bi = (bi + 1) % k;
            return true;
        } else {
            return false;
        }        
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : nums[fi];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : nums[bi];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == k;
    }
private:
    vector<int> nums;
    int size;
    int k;
    int fi;
    int bi;
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
