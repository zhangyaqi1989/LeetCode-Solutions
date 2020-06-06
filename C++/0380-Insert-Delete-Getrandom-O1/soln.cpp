class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (idxes.find(val) == idxes.end()) {
            idxes[val] = vals.size();
            vals.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (idxes.find(val) != idxes.end()) {
            int idx = idxes[val];
            int top = vals.back();
            idxes.erase(val);
            vals.pop_back();
            if (top != val) {
                vals[idx] = top;
                idxes[top] = idx;
            }
            return true;
        }
        return false;
        
    }

    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % (vals.size());
        return vals[idx];
    }
private:
    vector<int> vals;
    unordered_map<int, int> idxes;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
