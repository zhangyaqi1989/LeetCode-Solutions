#include<algorithm>
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.insert(t);
        auto lo = pings.lower_bound(t - 3000);
        pings.erase(pings.begin(), lo);
        return pings.size();
    }
private:
    set<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
