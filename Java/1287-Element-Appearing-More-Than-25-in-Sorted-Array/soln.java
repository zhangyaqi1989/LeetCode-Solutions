class Solution {
    public int findSpecialInteger(int[] arr) {
        int lo = 0, cnt = 0;
        int n = arr.length;
        for(int i = 0; i < n; ++i) {
            if (arr[i] != arr[lo]) {
                if (cnt > n / 4) return arr[lo];
                lo = i;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        return arr[n - 1];
    }
}
