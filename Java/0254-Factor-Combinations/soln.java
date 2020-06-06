class Solution {
    public List<List<Integer>> getFactors(int n) {
        List<Integer> factors = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        helper(n, 2, factors, ans);
        return ans;
    }
    
    public void helper(int n, int num, List<Integer> factors, List<List<Integer>> ans) {
        int i = num;
        while (i * i <= n) {
            if (n % i == 0) {
                factors.add(i);
                factors.add(n / i);
                List<Integer> temp = new ArrayList<Integer>(factors);
                ans.add(temp);
                factors.remove(factors.size() - 1);
                helper(n / i, i, factors, ans);
                factors.remove(factors.size() - 1);
            }
            ++i;
        }
    }
}
