class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> memo = new HashMap<>();
        int n = matrix[0].length;
        for(int [] row : matrix) {
            StringBuilder sb1 = new StringBuilder(), sb2 = new StringBuilder();
            for(int j = 0; j < n; ++j) {
                if (row[j] == 1) {
                    sb1.append("1");
                    sb2.append("0");
                } else {
                    sb1.append("0");
                    sb2.append("1");
                }
            }
            String s1 = sb1.toString(), s2 = sb2.toString();
            memo.put(s1, memo.getOrDefault(s1, 0) + 1);
            memo.put(s2, memo.getOrDefault(s2, 0) + 1);
        }
        int ans = 0;
        for(int v : memo.values()) ans = Math.max(ans, v);
        return ans;
    }
}
