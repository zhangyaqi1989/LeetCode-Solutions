class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> counter(n + 2, 0);
        for (auto & booking : bookings) {
            int i = booking[0], j = booking[1], k = booking[2];
            counter[i] += k;
            counter[j + 1] -= k;
        }
        vector<int> ans;
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            cnt += counter[i];
            ans.push_back(cnt);
        }
        return ans;
    }
};
