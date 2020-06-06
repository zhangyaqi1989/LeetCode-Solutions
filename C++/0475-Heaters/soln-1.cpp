class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.empty()) return 0;
        if (heaters.empty()) return INT_MAX;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        int min_dis = 0;
        int lo = 0, n = heaters.size();
        for(int house : houses) {
            while (lo < n && heaters[lo] < house) {
                ++lo;
            }
            if (lo < n) {
                if (lo == 0) ans = max(ans, heaters[lo] - house);
                else ans = max(ans, min(heaters[lo] - house, house - heaters[lo - 1]));
            } else {
                ans = max(ans, houses.back() - heaters.back());
                break;
            }
            
            
        }
        return ans;
    }
};
