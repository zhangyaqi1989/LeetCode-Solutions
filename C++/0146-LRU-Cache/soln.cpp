class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {}
    
    int get(int key) {
        auto it = m_.find(key);
        if(it == m_.end()) return -1;
        int val = it->second->second;
        cache_.erase(it->second);
        cache_.push_front({key, val});
        it->second = cache_.begin();
        return val;
    }
    
    void put(int key, int value) {
        auto it = m_.find(key);
        if (it != m_.end()) { // already in
            cache_.erase(it->second);
            cache_.push_front({key, value});
            it->second = cache_.begin();
            
        } else { // new 
            if (m_.size() < capacity_) {
                cache_.push_front({key, value});
                m_[key] = cache_.begin();
            } else {
                // remove the last one
                auto last = cache_.back();
                m_.erase(last.first);
                cache_.pop_back();
                cache_.push_front({key, value});
                m_[key] = cache_.begin();
            }
        }
    }
    
    
private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
