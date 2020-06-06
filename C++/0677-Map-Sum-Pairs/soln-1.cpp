class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        data[key] = val;
    }
    
    int sum(string prefix) {
        int n = prefix.length();
        int ans = 0;
        for(auto & p : data) {
            if (p.first.substr(0, n) == prefix) ans += p.second;
        }
        return ans;
    }
private:
    unordered_map<string, int> data;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
