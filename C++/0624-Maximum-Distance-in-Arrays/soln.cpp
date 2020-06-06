class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = 10000, mx = -10000;
        for(auto & array : arrays) {
            ans = max(ans, max(mx - array.front(), array.back() - mn));
            mx = max(mx, array.back());
            mn = min(mn, array.front());
        }
        return ans;
    }
};