class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lo = -1;
        int ans = 1, n = seats.size();
        for(int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (lo == -1) {
                    ans = max(ans, i);
                } else {
                    ans = max(ans, (i - lo) / 2);
                }
                lo = i;
            }
            // cout << ans << endl;
        }
        return max(n - 1 - lo, ans);
    }
};
