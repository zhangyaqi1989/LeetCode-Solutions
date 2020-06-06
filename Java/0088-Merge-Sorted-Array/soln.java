class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        int val;
        while (j >= 0) {
            if (i < 0) {
                val = nums2[j--];
            } else {
                val = nums1[i] <= nums2[j] ? nums2[j--] : nums1[i--];
            }
            nums1[k--] = val;
        }
    }
}
