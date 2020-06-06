class TwoSum {
    unordered_multiset<int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        m.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(int num : m) {
            int cnt = num == value - num ? 1 : 0;
            if (m.count(value - num) > cnt) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
