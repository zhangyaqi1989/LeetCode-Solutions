class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> ans = new ArrayList<>();
        ans.add(0);
        for(int i = 0; i < n; ++i) {
            int inc = (1 << i);
            int m = ans.size();
            for(int j = m - 1; j >= 0; --j) {
                ans.add(ans.get(j) + inc);
            }
        }
        return ans;
    }
}
