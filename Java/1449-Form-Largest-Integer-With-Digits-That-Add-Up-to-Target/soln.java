class Solution {
    public String largestNumber(int[] cost, int target) {
        String [] memo = new String[target + 1];
        Arrays.fill(memo, "-");
        return dp(target, cost, memo);
    }
    
    private boolean greater(String cand, String ans) {
        if(cand.length() == ans.length()) return cand.compareTo(ans) > 0;
        else return cand.length() > ans.length();
    }
    
    private String dp(int target, int [] cost, String [] memo) {
        if(target == 0) return "";
        if(memo[target] != "-") return memo[target];
        String ans = "0";
        for(int i = 0; i < 9; ++i) {
            if (target >= cost[i]) {
                 String cand = Integer.toString(i + 1) + dp(target - cost[i], cost, memo);
                if(cand.charAt(cand.length() - 1) != '0' && greater(cand, ans)) {
                    ans = cand;
                }
            }

        }
        memo[target] = ans;
        return ans;
    }
}
