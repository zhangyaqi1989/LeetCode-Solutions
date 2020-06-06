class Solution {
public:
    int binaryGap(int N) {
        int idx = 0, pre = -1, ans = 0;
        while (N != 0) {
            int d = N % 2;
            N >>= 1;
            if (d == 1) {
                if (pre != -1) ans = max(ans, idx - pre);
                pre = idx;
            }
            idx += 1;
        }
        return ans;
    }
};
