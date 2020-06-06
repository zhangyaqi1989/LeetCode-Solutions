class Solution {
    public int lastStoneWeightII(int[] stones) {
        Set<Integer> dp = new HashSet<>();
        dp.add(0);
        for(int stone : stones) {
            Set<Integer> temp = new HashSet<>();
            for(int item : dp) {
                temp.add(item + stone);
                temp.add(item - stone);
            }
            dp = temp;
        }
        int ans = Integer.MAX_VALUE;
        for(int item : dp) ans = Math.min(ans, Math.abs(item));
        return ans;
    }
}
