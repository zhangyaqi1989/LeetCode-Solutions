class SummaryRanges {
    set<pair<int, int>> ranges;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        ranges.clear();
    }
    
    void addNum(int val) {
        auto it = ranges.lower_bound({val, val});
        if (it != ranges.begin() && prev(it)->second + 1 >= val) it = prev(it);
        int start = val, end = val;
        while (it != ranges.end() && val + 1 >= it->first && val - 1 <= it->second) {
            start = min(start, it->first);
            end = max(end, it->second);
            it = ranges.erase(it);
        }
        ranges.insert({start, end});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto & p : ranges) {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
