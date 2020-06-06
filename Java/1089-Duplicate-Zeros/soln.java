class Solution {
    public void duplicateZeros(int[] arr) {
        int [] dup = arr.clone();
        int idx = 0, n = arr.length;
        for(int i = 0; i < n && idx < n; ++i) {
            arr[idx++] = dup[i];
            if (idx >= n) break;
            if (dup[i] == 0) arr[idx++] = 0;
        }
    }
}
