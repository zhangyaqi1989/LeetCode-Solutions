class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push_back(t);
        int lo = lower_bound(pings.begin(), pings.end(), t - 3000) - pings.begin();
        return pings.size() - lo;
    }
    
private:
    vector<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
