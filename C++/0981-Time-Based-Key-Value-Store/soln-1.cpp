class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = dict[key].upper_bound(timestamp);
        if (it == dict[key].begin()) return "";
        else return prev(it)->second;
    }
    
private:
    unordered_map<string, map<int, string>> dict;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
