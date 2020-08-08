class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int idx = 0;
        for(int nxt = 1; ; ++nxt) {
            if(idx < n && arr[idx] == nxt) {
                ++idx;
            } else {
                if(k-- == 1) return nxt;
            }
        }
    }
}
