class Solution {
    public int longestWPI(int[] hours) {
        int n = hours.length;
        Map<Integer, Integer> memo = new HashMap<>();
        memo.put(0, -1);
        int mx_len = 0;
        int acc = 0;
        for(int i = 0; i < n; ++i) {
            int hour = hours[i];
            if (hour > 8) ++acc;
            else --acc;
            if (acc > 0) mx_len = i + 1;
            if (!memo.containsKey(acc)) memo.put(acc, i);
            if (memo.containsKey(acc - 1)) mx_len = Math.max(mx_len, i - memo.get(acc - 1));
        }
        return mx_len;
    }
}
