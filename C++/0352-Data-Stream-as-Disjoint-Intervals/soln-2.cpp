class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto hi = inters_.upper_bound(val);
        auto lo = hi; 
        if (hi != inters_.begin()) {
            lo = prev(lo);
            int s = lo->first, e = lo->second;
            if (s <= val && val <= e) return;
            else {
                if (val == e + 1) {
                    lo->second = e + 1;
                    auto it = next(lo);
                    if(it != inters_.end() && it->first == lo->second + 1) {
                        lo->second = it->second;
                        inters_.erase(it);
                    }
                    // while (it != inters_.end()) {
                    //     if (it->first == lo->second) {
                    //         lo->second = it->
                    //     } else {
                    //         break;
                    //     }
                    // }
                } else {
                    inters_.insert({val, val});
                    lo = inters_.find(val);
                    auto it = next(lo);
                    if(it != inters_.end() && it->first == lo->second + 1) {
                        lo->second = it->second;
                        inters_.erase(it);
                    }
                    
                }
            }
        } else {
            inters_.insert({val, val});
            lo = inters_.find(val);
            auto it = next(lo);
            if(it != inters_.end() && it->first == lo->second + 1) {
                lo->second = it->second;
                inters_.erase(it);
            }            
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(const auto & p : inters_) {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
private:
    map<int, int> inters_;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
