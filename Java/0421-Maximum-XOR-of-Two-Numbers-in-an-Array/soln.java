class Solution {
    public int findMaximumXOR(int[] nums) {
        int mx = 0;
        for(int i = 30; i >= 0; --i) {
            Set<Integer> prefixes = new HashSet<>();
            for(int num : nums) prefixes.add(num >> i);
            mx <<= 1;
            int cand = mx + 1;
            for(int prefix : prefixes) {
                if (prefixes.contains(prefix ^ cand)) {
                    mx = cand;
                    break;
                }
            }
        }
        return mx;
    }
}
