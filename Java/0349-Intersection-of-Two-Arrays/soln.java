class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> nums = new HashSet<>();
        for(int num : nums1) nums.add(num);
        Set<Integer> set = new HashSet<>();
        for(int num : nums2) {
            if (nums.contains(num)) {
                set.add(num);
            }
        }
        int n = set.size();
        int [] ans = new int [n];
        int idx = 0;
        for(int num : set) ans[idx++] = num;
        return ans;
    }
}
