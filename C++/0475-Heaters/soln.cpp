class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty()) return 0;
        if (heaters.empty()) return INT_MAX;
        // sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        int min_dis = 0;
        for(int house : houses) {
            auto lo = lower_bound(heaters.begin(), heaters.end(), house);
            if (lo == heaters.begin()) {
                min_dis = heaters[0] - house;
            } else if (lo == heaters.end()) {
                min_dis = house - heaters.back();
            } else {
                min_dis = min(*lo - house, house - *(prev(lo)));
            }
            ans = max(ans, min_dis);
        }
        return ans;
    }
};
