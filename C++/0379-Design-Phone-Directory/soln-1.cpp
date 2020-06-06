class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max_number_ = maxNumbers;
        availables_.resize(max_number_);
        iota(availables_.begin(), availables_.end(), 0);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (availables_.empty()) return -1;
        int num = availables_.back();
        availables_.pop_back();
        used_.insert(num);
        return num;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number >= max_number_ || used_.find(number) != used_.end()) return false;
        return true;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < max_number_) {
            auto it = used_.find(number);
            if (it != used_.end()) {
                used_.erase(it);
                availables_.push_back(number);
            }
        }
    }
private:
    int max_number_;
    unordered_set<int> used_;
    vector<int> availables_;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
