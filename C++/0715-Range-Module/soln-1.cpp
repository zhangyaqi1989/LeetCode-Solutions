class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = ranges_.upper_bound(right);
        if (it == ranges_.begin()) {
            ranges_.insert({left, right});
        } else {
            int hi = right, lo = left;
            it = prev(it);
            vector<int> removes;
            while(it->second >= lo) {
                lo = min(lo, it->first);
                hi = max(hi, it->second);
                removes.push_back(it->first);
                if (it != ranges_.begin()) it = prev(it);
                else break;
            }
            for(int num : removes) ranges_.erase(num);
            ranges_.insert({lo, hi});
        }
        // cout << "add " << left << " " << right << ": ";
        // for(auto & p : ranges_) cout << p.first << " " << p.second << ", ";
        // cout << endl;
    }
    
    bool queryRange(int left, int right) {
        // cout << "query " << left << " " << right << endl;
        auto it = ranges_.upper_bound(right);
        if (it == ranges_.begin()) return false;
        it = prev(it);
        return it->first <= left && it->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = ranges_.upper_bound(right);
        if (it != ranges_.begin()) {
            it = prev(it);
            vector<pair<int, int>> adds;
            vector<int> removes;
            while (it->second >= left) {
                removes.push_back(it->first);
                if (it->second > right) adds.emplace_back(right, it->second);
                if (it->first < left) adds.emplace_back(it->first, left);
                if (it != ranges_.begin()) it = prev(it);
                else break;
            }
            // cout << ranges_.size() << endl;
            for(int num : removes) ranges_.erase(num);
            for(auto & p : adds) ranges_.insert({p.first, p.second});
        }
        // cout << "remove " << left << " " << right << ": ";
        // for(auto & p : ranges_) cout << p.first << " " << p.second << ", ";
        // cout << endl;
    }
    
private:
    map<int, int> ranges_;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
