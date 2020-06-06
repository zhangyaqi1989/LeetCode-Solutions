class TwoSum {
private:
    unordered_map<int, int> dict;

public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        dict[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto it = dict.begin(); it != dict.end(); ++it)
        {
            if((it->first == value - it->first && it->second > 1) || (it->first != value - it->first && dict.find(value - it->first) != dict.end()))
                return true;
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