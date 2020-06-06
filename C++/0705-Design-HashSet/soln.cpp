class MyHashSet {
private:
    static const int N = 1337;
    set<int> arr[N];
    int getIdx(int key) {return key % N;}
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        int idx = getIdx(key);
        arr[idx].insert(key);
    }
    
    void remove(int key) {
        int idx = getIdx(key);
        arr[idx].erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = getIdx(key);
        return arr[idx].find(key) != arr[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
