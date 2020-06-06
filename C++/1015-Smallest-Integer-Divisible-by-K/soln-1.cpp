class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 5 == 0 || K % 2 == 0) return -1;
        int num = 1, ans = 1;
        while (num % K != 0) {
            num = (num * 10 + 1) % K;
            ++ans;
        }
        return ans;
    }
};
