class Solution {
public:
    int binaryGap(int N) {
        int pre = -1;
        int i = 0, ans = 0;
        while (N) {
            if (N % 2 == 1) {
                if (pre != -1) {
                    ans = max(ans, i - pre);
                }
                pre = i;
            }
            ++i;
            N /= 2;
        }
        return ans;
    }
};
