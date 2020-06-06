typedef long long ll;
struct Event {
    bool isenter;
    int x1;
    int x2;
};
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const ll kMod = 1000000007LL;
        map<int, vector<Event>> events; // y : vector of events
        for(const auto & rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            events[y1].push_back({true, x1, x2});
            events[y2].push_back({false, x1, x2});
        }
        multiset<pair<int, int>> xranges;
        ll area = 0LL;
        int pre_y = -1;
        int dx = 0, dy = 0, y = 0;
        for(const auto & p : events) {
            y = p.first;
            // cout << y << endl;
            for(const auto & e : p.second) {
                if (e.isenter) {
                    xranges.insert({e.x1, e.x2});
                } else {
                    xranges.erase(xranges.find({e.x1, e.x2}));
                }
            }
            if (pre_y != -1) {
                dy = y - pre_y;
                // cout << dx << endl;
                area = (area + (ll) dy * dx % kMod) % kMod; 
            }
            // update dx
            vector<pair<int, int>> xs;
            for(const auto & xrange : xranges) {
                int x1, x2;
                tie(x1, x2) = xrange;
                // cout << "(" << x1 << ", " << x2 << "), ";
                if (xs.empty() || x1 > xs.back().second) {
                    xs.emplace_back(x1, x2);
                } else {
                    xs.back().second = max(xs.back().second, x2);
                }
            }
            // cout << endl;
            dx = 0;
            for(const auto & xrange : xs) {
                dx += xrange.second - xrange.first;
            }
            pre_y = y;
        }
        return area;
        
    }
};
