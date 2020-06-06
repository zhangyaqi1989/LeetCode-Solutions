class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        // [left, right)
        vector<pair<int, int>> temp;
        int n = intervals.size();
        for(int i = 0; i <= n; ++i) {
            if (i == n || intervals[i].first > right) {
                temp.push_back({left, right});
                while(i < n) temp.push_back(intervals[i++]);
            } else if (intervals[i].second < left) {
                temp.push_back(intervals[i]);
            } else {
                left = min(left, intervals[i].first);
                right = max(right, intervals[i].second);
            }
        }
        swap(temp, intervals);
    }
    
    bool queryRange(int left, int right) {
        // for(int i = 0; i < intervals.size(); ++i) {
        //     cout << "[" << intervals[i].first << ", " << intervals[i].second << "] ";
        // }
        // cout << endl;
        int n = intervals.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid].second < left) {
                lo = mid + 1;
            } else if (intervals[mid].first > right) {
                hi = mid - 1;
            } else {
                return intervals[mid].first <= left && intervals[mid].second >= right;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<pair<int, int>> temp;
        int n = intervals.size();
        for(int i = 0; i < n; ++i) {
            if (intervals[i].second < left) {
                temp.push_back(intervals[i]);
            } else if (intervals[i].first > right) {
                temp.push_back(intervals[i]);
            } else {
                if (intervals[i].first < left) temp.push_back({intervals[i].first, left});
                if (intervals[i].second > right) temp.push_back({right, intervals[i].second});
            }
        }
        swap(temp, intervals);
    }
    
private:
    vector<pair<int, int>> intervals;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
