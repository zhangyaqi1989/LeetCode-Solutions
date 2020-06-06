class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) return 0;
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        int cnt = 0;
        for(int num : counter.keySet()) {
            if (k == 0) {
                if (counter.get(num) > 1) ++cnt;
            } else {
                if (counter.containsKey(num + k)) {
                    ++cnt;
                }
            }

        }
        return cnt;
    }
}
