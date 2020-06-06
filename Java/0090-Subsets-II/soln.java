class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer> set = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        helper(0, nums, set, ans);
        return ans;
    }
    
    public void helper(int idx, int[] nums, List<Integer> set, List<List<Integer>> ans) {
        List<Integer> temp = new ArrayList<>(set);
        ans.add(temp);            
        if (idx < nums.length) {
            for(int i = idx; i < nums.length; ++i) {
                if (i > idx && nums[i] == nums[i - 1]) continue;
                set.add(nums[i]);
                helper(i + 1, nums, set, ans);
                set.remove(set.size() - 1);
            } 
        }
    }
}
