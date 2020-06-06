class Solution {
    public int[] sortByBits(int[] arr) {
        int n = arr.length;
        int [][] pairs = new int [n][2];
        for(int i = 0; i < n; ++i) {
            int cnt = 0, temp = arr[i];
            while (temp != 0) {
                cnt += temp % 2;
                temp /= 2;
            }
            pairs[i][0] = cnt;
            pairs[i][1] = arr[i];
        }
        Arrays.sort(pairs, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        int [] ans = new int [n];
        for(int i = 0; i < n; ++i) {
            ans[i] = pairs[i][1];
        }
        return ans;
    }
}
