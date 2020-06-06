ass PhoneDirectory {
private:
    int mx;
    unordered_set<int> used;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        mx = maxNumbers;
        used.clear();
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (used.size() == mx) return -1;
        while (true) {
            int num = rand() % mx;
            if (!used.count(num)) {
                used.insert(num);
                return num;
            } 
        }
        
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return used.count(number) == 0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
