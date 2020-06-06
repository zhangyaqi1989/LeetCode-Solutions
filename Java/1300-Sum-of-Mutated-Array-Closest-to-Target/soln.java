class Solution {
    public int findBestValue(int[] arr, int target) {
        int n = arr.length;
        int best_diff = Integer.MAX_VALUE, best_val = 0;
        int left = 0;
        Arrays.sort(arr);
        int hi = arr[n - 1];
        int idx = 0;
        for(int val = 0; val <= hi; ++val) {
            while(idx < n && arr[idx] <= val) left += arr[idx++];
            int diff = Math.abs(left + (n - idx) * val - target);
            if (diff < best_diff) {
                best_diff = diff;
                best_val = val;
            }
        }
        return best_val;
    }
}
