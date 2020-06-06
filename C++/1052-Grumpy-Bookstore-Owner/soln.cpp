class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int mx = 0, total = 0, un = 0, n = grumpy.size(), cur = 0;
        for(int i = 0; i < n; ++i) {
            total += customers[i];
            if (grumpy[i] == 0) customers[i] = 0;
        }
        for(int i = 0; i < n; ++i) {
            un += customers[i];
            if (i < X) {
                cur += customers[i];
                mx += customers[i];
            } else {
                cur += customers[i] - customers[i - X];
                mx = max(mx, cur);
            }
        }
        return total - (un - mx);
    }
};
