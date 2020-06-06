class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        dq.push_back(t);
        while (dq.size() && t - 3000 > dq.front()) {
            dq.pop_front();
        }
        return dq.size();
    }
private:
    deque<int> dq;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */