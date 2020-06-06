class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        nums_.clear();
        nums_.push_back({});
        capacity_ = capacity;
        lefts_.insert({0});
    }
    
    void push(int val) {
        int idx = *lefts_.begin();
        nums_[idx].push_back(val);
        rights_.insert(idx);
        if(nums_[idx].size() == capacity_) {
            lefts_.erase(idx);
        }
        if (lefts_.empty()) {
            lefts_.insert(nums_.size());
            nums_.push_back({});
        }
    }
    
    int pop() {
        if (rights_.empty()) return -1;
        int idx = *rights_.rbegin();
        int val = nums_[idx].back();
        nums_[idx].pop_back();
        if (nums_[idx].empty()) rights_.erase(idx);
        lefts_.insert(idx);
        return val;
    }
    
    int popAtStack(int index) {
        if (index >= nums_.size() || nums_[index].empty()) return -1;
        int val = nums_[index].back();
        nums_[index].pop_back();
        if(nums_[index].empty()) rights_.erase(index);
        lefts_.insert(index);
        return val;
    }
    
private:
    // inf number of stacks with capacity
    // push to the leftmost not full stack
    // pop from the rightmost no empty stack
    // pop from stack at idx
    vector<vector<int>> nums_;
    int capacity_;
    set<int> lefts_;
    set<int> rights_;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
