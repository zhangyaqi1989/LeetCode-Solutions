class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for(int num : nums) s.add(num);
        int ans = 0;
        for(int x : s) {
            if (!s.contains(x - 1)) {
                int y = x + 1;
                while (s.contains(y)) ++y;
                ans = Math.max(ans, y - x);
            }
        }
        return ans;
    }
}
