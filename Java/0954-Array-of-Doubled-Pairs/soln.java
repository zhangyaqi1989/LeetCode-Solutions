class Solution {
    public boolean canReorderDoubled(int[] A) {
        List<Integer> poss = new ArrayList<>();
        List<Integer> negs = new ArrayList<>();
        for(int num : A) {
            if (num >= 0) poss.add(num);
            else negs.add(-num);
        }
        return helper(poss) && helper(negs);
    }
    
    public boolean helper(List<Integer> nums) {
        if (nums.size() % 2 == 1) return false;
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : nums) counter.put(num, counter.getOrDefault(num, 0) + 1);
        Collections.sort(nums);
        for(int num : nums) {
            if (counter.get(num) > 0) {
                if (counter.get(num * 2) == null || counter.get(num * 2) <= 0) return false;
                counter.put(num, counter.get(num) - 1);
                counter.put(num * 2, counter.get(2 * num) - 1);
            }
        }
        return true;
    }
}
