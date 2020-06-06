class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int mx = INT_MIN;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        heaters.push_back(1e9 * 2);
        int idx = 0, n = heaters.size();
        for(int house : houses) {
            while (house >= heaters[idx]) ++idx;
            int temp = heaters[idx] - house;
            if (idx > 0) temp = min(temp, house - heaters[idx - 1]);
            mx = max(mx, temp);
        }
        return mx;
    }
};
