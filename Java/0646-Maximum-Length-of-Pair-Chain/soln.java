class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> (a[1] - b[1]));
        int cnt = 0, low = Integer.MIN_VALUE;
        for(int[] pair : pairs) {
            int start = pair[0], end = pair[1];
            if (start > low) {
                low = end;
                ++cnt;
            }
        }
        return cnt;
    }
}
