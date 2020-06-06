class Solution {
public:
    Solution(vector<int>& w) {
        const int n = w.size();
        prefix_.push_back(w[0]);
        for(int i = 1; i < n; ++i) {
            prefix_.push_back(prefix_.back() + w[i]);
        }
        total_ = prefix_.back();
    }
    
    int pickIndex() {
        // 1 2 3
        // 1 3 6
        int r = rand() % total_;
        int idx = upper_bound(prefix_.begin(), prefix_.end(), r) - prefix_.begin();
        return idx;
    }

private:
    vector<int> prefix_;
    int total_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
