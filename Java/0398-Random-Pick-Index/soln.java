class Solution {
    private Map<Integer, List<Integer>> m;
    private Random random;

    public Solution(int[] nums) {
        m = new HashMap<>();
        random = new Random();
        int n = nums.length;
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            m.putIfAbsent(num, new ArrayList<>());
            m.get(num).add(i);
        }
    }
    
    public int pick(int target) {
        List<Integer> lst = m.get(target);
        int idx = random.nextInt(lst.size());
        return lst.get(idx);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
