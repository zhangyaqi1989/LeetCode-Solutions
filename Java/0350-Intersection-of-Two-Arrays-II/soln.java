class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> c1 = count(nums1);
        Map<Integer, Integer> c2 = count(nums2);
        List<Integer> ans = new ArrayList<>();
        for(int num : c1.keySet()) {
            int cnt = c1.get(num);
            if (c2.containsKey(num)) {
                cnt = Math.min(cnt, c2.get(num));
                for(int i = 0; i < cnt; ++i) {
                    ans.add(num);
                }
            }
        }
        int [] nums = new int [ans.size()];
        for(int i = 0; i < ans.size(); ++i) {
            nums[i] = ans.get(i);
        }
        return nums;
    }
    
    private Map<Integer, Integer> count(int [] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        return counter;
    }
}
