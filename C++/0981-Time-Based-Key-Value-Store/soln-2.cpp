class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        records_[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it = records_.find(key);
        if (it == records_.end()) return "";
        auto it1 = lower_bound(begin(it->second), end(it->second), make_pair(timestamp + 1, string("")));
        if (it1 != it->second.begin()) {
            return prev(it1)->second;
        } else return "";
        
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> records_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
