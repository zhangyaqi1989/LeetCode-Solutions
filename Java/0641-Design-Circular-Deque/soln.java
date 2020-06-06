class MyCircularDeque {
    private int [] nums;
    private int size;
    private int k;
    private int fi;
    private int bi;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        nums = new int [k];
        size = 0;
        this.k = k;
        fi = -1;
        bi = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
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
    public boolean insertLast(int value) {
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
    public boolean deleteFront() {
        if (!isEmpty()) {
            --size;
            if (--fi < 0) fi += k;
            return true;
        } else {
            return false;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (!isEmpty()) {
            --size;
            bi = (bi + 1) % k;
            return true;
        } else {
            return false;
        }        
    }
    
    /** Get the front item from the deque. */
    public int getFront() {
        return isEmpty() ? -1 : nums[fi];
    }
    
    /** Get the last item from the deque. */
    public int getRear() {
        return isEmpty() ? -1 : nums[bi];
    }
    
    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
       return size == 0; 
    }
    
    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return size == k;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
