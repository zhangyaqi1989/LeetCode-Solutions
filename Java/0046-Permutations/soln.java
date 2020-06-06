class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if (nums.length == 0) return ans;
        ans.add(new ArrayList<>());
        for(int num : nums) {
            List<List<Integer>> temp = new ArrayList<>();
            for(List<Integer> lst : ans) {
                for(int i = 0; i <= lst.size(); ++i) {
                    List<Integer> x = new ArrayList<>(lst);
                    x.add(i, num);
                    temp.add(x);
                }
            }
            ans = temp;
        }
        return ans;
    }
}
