class Solution {
    public int getKth(int lo, int hi, int k) {
        Map<Integer, Integer> memo = new HashMap<>();
        int n = hi - lo + 1;
        int [][] pairs = new int[n][2];
        for(int i = 0; i < n; ++i) {
            pairs[i][0] = lo + i;
            pairs[i][1] = computePower(lo + i, memo);
        }
        Arrays.sort(pairs, (a, b) -> (a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]));
        return pairs[k - 1][0];
    }
    
    private int computePower(int num, Map<Integer, Integer> memo) {
        if (memo.containsKey(num)) return memo.get(num);
        if (num == 1) return 0;
        int result = 1;
        if (num % 2 == 0) {
            result += computePower(num / 2, memo);
        } else {
            result += computePower(num * 3 + 1, memo);
        }
        memo.put(num, result);
        return result;
    }
}
