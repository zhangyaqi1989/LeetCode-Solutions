class Solution {
public:
    int numWays(int n, int k) {
        // no more than two adjacent fence
        // number of ways
        if (n == 0) return 0;
        if (k == 1 && n <= 2) return 1;
        int same = 0, diff = k;
        for(int i = 1; i < n; ++i) {
            // same, diff = diff, (same + diff) * (k - 1);
            int temp = same;
            same = diff;
            diff = (temp + diff) * (k - 1);
        }
        return same + diff;
        
    }
};
