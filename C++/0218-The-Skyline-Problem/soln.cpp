class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Event> events;
        for(const auto & b : buildings) {
            int l = b[0], r = b[1], h = b[2];
            events.push_back({l, h, 1});
            events.push_back({r, h, -1});
        }
        sort(events.begin(), events.end());
        multiset<int> actives;
        actives.insert(0);
        vector<vector<int>> ans;
        for(const auto & e : events) {
            if (e.type == 1) {
                if (e.y > *actives.rbegin()) {
                    ans.push_back({e.x, e.y});
                }
                actives.insert(e.y);
            } else {
                actives.erase(actives.find(e.y));
                if (e.y > *actives.rbegin()) {
                    ans.push_back({e.x, *actives.rbegin()});
                }
            }
        }
        return ans;
    }
    
private:
    struct Event {
        int x;
        int y;
        int type;
        bool operator< (const Event & rhs) const {
            return rhs.x == x ? type * y > rhs.type * rhs.y : x < rhs.x;
        }
    };
};
