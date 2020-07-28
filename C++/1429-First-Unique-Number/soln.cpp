class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        idx_ = 0;
        nums_ = nums;
        for(int num : nums) ++counter_[num];
    }
    
    int showFirstUnique() {
        while(idx_ < nums_.size() && counter_[nums_[idx_]] > 1) {
            ++idx_;
        }
        return idx_ < nums_.size() ? nums_[idx_] : -1;
    }
    
    void add(int value) {
        nums_.push_back(value);
        ++counter_[value];
    }
    
private:
    vector<int> nums_;
    map<int, int> counter_;
    int idx_;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
