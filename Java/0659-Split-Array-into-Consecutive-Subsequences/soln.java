class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer, Integer> lefts = new HashMap<>();
        Map<Integer, Integer> ends = new HashMap<>();
        for(int num : nums) {
            lefts.put(num, lefts.getOrDefault(num, 0) + 1);
        }
        for(int num : nums) {
            if (lefts.getOrDefault(num, 0) == 0) continue;
            lefts.put(num, lefts.get(num) - 1);
            if (ends.getOrDefault(num - 1, 0) > 0) {
                ends.put(num - 1, ends.get(num - 1) - 1);
                ends.put(num, ends.getOrDefault(num, 0) + 1);
            } else if (lefts.getOrDefault(num + 1, 0) > 0 && lefts.getOrDefault(num + 2, 0) > 0) {
                lefts.put(num + 1, lefts.get(num + 1) - 1);
                lefts.put(num + 2, lefts.get(num + 2) - 1);
                ends.put(num + 2, ends.getOrDefault(num + 2, 0) + 1);
                
            }
            else return false;
        }
        return true;
    }
}
