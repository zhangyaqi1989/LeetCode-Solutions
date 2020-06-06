class MajorityChecker {

public:
    MajorityChecker(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            idxes_[arr[i]].push_back(i);
        }
        nums_ = move(arr);
    }
    
    int query(int left, int right, int threshold) {
        for(int i = 0; i < 20; ++i) {
            int r = rand() % (right - left + 1) + left;
            int num = nums_[r];
            const auto & temp = idxes_[num];
            int l_idx = lower_bound(temp.begin(), temp.end(), left) - temp.begin();
            int r_idx = upper_bound(temp.begin(), temp.end(), right) - temp.begin();
            if (r_idx - l_idx >= threshold) return num;
        }
        return -1;
    }
private:
    unordered_map<int, vector<int>> idxes_;
    vector<int> nums_;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
