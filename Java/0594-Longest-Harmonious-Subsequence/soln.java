class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : nums) {
            if (counter.get(num) == null) {
                counter.put(num, 0);
            }
            counter.put(num, counter.get(num) + 1);
        }
        int ans = 0;
        for(int num : counter.keySet()) {
            if (counter.get(num + 1) != null) {
                ans = Math.max(ans, counter.get(num + 1) + counter.get(num));
            }
        }
        return ans;
    }
}
