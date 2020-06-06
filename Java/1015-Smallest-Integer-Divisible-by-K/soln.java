class Solution {
    public int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        int rem = 1, power = 1, ans = 1;
        while (rem % K != 0) {
            ++ans;
            power = power * 10 % K;
            rem = (rem + power) % K;
        }
        return ans;        
    }
}
