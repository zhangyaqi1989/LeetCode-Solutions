class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        k = Math.abs(k);
        m.put(0, -1);
        int acc = 0;
        for (int i = 0; i < nums.length; ++i) {
            acc += nums[i];
            if (k != 0) acc = acc % k;
            if (m.get(acc) != null) {
                if (i - m.get(acc) > 1) return true;
            } else {
                m.put(acc, i);
            }
        }
        return false;
    }
}
