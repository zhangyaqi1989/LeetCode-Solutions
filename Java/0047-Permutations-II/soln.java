class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        for(int num : nums) {
            List<List<Integer>> temp = new ArrayList<>();
            for(List<Integer> lst : ans) {
                for(int i = 0; i <= lst.size(); ++i) {
                    if (i > 0 && lst.get(i - 1) == num) break;
                    List<Integer> clst = new ArrayList<>(lst);
                    clst.add(i, num);
                    temp.add(clst);
                }
            }
            ans = temp;
        }
        return ans;
    }
}
