class Solution {
    public int longestSubsequence(int[] arr, int diff) {
        Map<Integer, Integer> dp = new HashMap<>();
        int ans = 1;
        for(int num : arr) {
            if(dp.containsKey(num - diff)) {
                int cnt = dp.get(num - diff);
                dp.remove(num - diff);
                ans = Math.max(ans, cnt + 1);
                dp.put(num, Math.max(dp.getOrDefault(num, 0), cnt + 1));
            } else {
                if(!dp.containsKey(num)) dp.put(num, 1);
            }
        }
        return ans;
    }
}
