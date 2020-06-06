class Solution {
    public int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split("\\.");
        String[] nums2 = version2.split("\\.");
        int n1 = nums1.length, n2 = nums2.length;
        int i1 = 0, i2 = 0;
        int v1, v2;
        while (i1 < n1 || i2 < n2) {
            if (i1 < n1) v1 = Integer.parseInt(nums1[i1++]);
            else v1 = 0;
            if (i2 < n2) v2 = Integer.parseInt(nums2[i2++]);
            else v2 = 0;
            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
        }
        return 0;
    }
}

