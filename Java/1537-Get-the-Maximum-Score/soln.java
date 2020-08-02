class Solution {
    public int maxSum(int[] nums1, int[] nums2) {
        final int N1 = nums1.length, N2 = nums2.length;
        long cur1 = 0, cur2 = 0, ans = 0;
        int i = 0, j = 0;
        while(i < N1 && j < N2) {
            if(nums1[i] < nums2[j]) {
                cur1 += nums1[i++];
            } else if(nums2[j] < nums1[i]) {
                cur2 += nums2[j++];
            } else {
                ans += Math.max(cur1, cur2) + nums1[i];
                ++i;
                ++j;
                cur1 = 0;
                cur2 = 0;
            }
        }
        while(i < N1) cur1 += nums1[i++];
        while(j < N2) cur2 += nums2[j++];
        return (int) ((ans + Math.max(cur1, cur2)) % 1000000007);
    }
}
