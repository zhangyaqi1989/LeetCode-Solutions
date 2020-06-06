class MyHashMap {
    static const int N = 1337;
    vector<pair<int, int>> lst[N];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    int getIdx(int key) {return key % N;}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = getIdx(key);
        bool update = false;
        for(auto & p : lst[idx]) {
            if(p.first == key) {
                p.second = value;
                update = true;
                break;
            }
        }
        if (!update) lst[idx].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = getIdx(key);
        for(auto & p : lst[idx]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = getIdx(key);
        for(int i = 0; i < lst[idx].size(); ++i) {
            if(lst[idx][i].first == key) {
                lst[idx].erase(lst[idx].begin() + i);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
