class Solution {
    public int numOfSubarrays(int[] arr) {
        int [] pres = {1, 0};
        int cur = 0;
        long ans = 0;
        for(int num : arr) {
            cur = (cur + num) % 2;
            ans += pres[1 - cur];
            ++pres[cur];
        }
        return (int) (ans % 1000000007);
    }
}
