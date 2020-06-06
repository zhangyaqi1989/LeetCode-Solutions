class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (idxes_.find(val) == idxes_.end()) {
            idxes_[val] = nums_.size();
            nums_.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(idxes_.find(val) == idxes_.end()) {
            return false;
        }
        int r_idx = idxes_[val];
        if (r_idx != nums_.size() - 1) {
            nums_[r_idx] = nums_.back();
            idxes_[nums_.back()] = r_idx;
        }   
        nums_.pop_back();
        idxes_.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        const int n = nums_.size();
        int idx = rand() % n;
        return nums_[idx];
    }
    
private:
    vector<int> nums_;
    unordered_map<int, int> idxes_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
