class Solution {
    public int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int ans = 1, num = 1;
        while (num % K != 0) {
            num = (num * 10 + 1) % K;
            ++ans;
        }
        return ans;
    }
}
