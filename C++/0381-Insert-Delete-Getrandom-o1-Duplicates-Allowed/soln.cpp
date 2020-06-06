class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int i = nums_.size();
        int j = idxes_[val].size();
        idxes_[val].push_back(i);
        nums_.emplace_back(val, j);
        return j == 0;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idxes_[val].empty()) return false;
        int i = idxes_[val].back();
        idxes_[val].pop_back();
        if (i + 1 != nums_.size()) { // not the last one, replace with the last one
            auto b = nums_.back();
            int rval = b.first;
            int j = b.second; // jth in idxes_[rval]
            idxes_[rval][j] = i;
            nums_[i].first = rval;
            nums_[i].second = j;
        }
        nums_.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        const int n = nums_.size();
        return nums_[rand() % n].first;
    }
    
private:
    vector<pair<int, int>> nums_;
    unordered_map<int, vector<int>> idxes_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
