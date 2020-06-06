struct Event {
    bool isenter;
    int x1;
    int x2;
    
    bool operator< (const Event & other) {
        return isenter < other.isenter;
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<int, vector<Event>> events;
        for(const auto & rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            events[y1].push_back({true, x1, x2});
            events[y2].push_back({false, x1, x2});
        }
        int xmin = -1, xmax = -1;
        int x_diff = -1;
        bool x_set = false;
        multiset<pair<int, int>> xranges;
        for(auto it = events.begin(); next(it) != events.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            int cnt = 0;
            for(auto & e : it->second) {
                if (e.isenter) {
                    auto pos_it = xranges.lower_bound({e.x1, e.x2});
                    if (pos_it != xranges.begin() && prev(pos_it)->second > e.x1) return false;
                    if (pos_it != xranges.end() && pos_it->first < e.x2) return false;
                    xranges.insert({e.x1, e.x2});
                    cnt += e.x2 - e.x1;
                } else {
                    cnt -= e.x2 - e.x1;
                    xranges.erase(xranges.find({e.x1, e.x2}));
                }
            }
            if (!x_set) x_diff = cnt;
            int cur_xmin = (*xranges.begin()).first, cur_xmax = (*xranges.rbegin()).second;
            if (cur_xmax - cur_xmin != x_diff) return false;
            if (!x_set) {
                xmin = cur_xmin;
                xmax = cur_xmax;
                x_set = true;
            } else {
                if (cnt != 0) return false;
                if (xmin != cur_xmin || xmax != cur_xmax) {
                    return false;
                }
            }
        }
        return true;
    }
};
