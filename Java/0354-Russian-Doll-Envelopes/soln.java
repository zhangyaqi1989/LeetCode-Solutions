class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> (a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]));
        int n = envelopes.length;
        int [] tails = new int[n];
        int len = 0;
        for(int [] enve : envelopes) {
            int h = enve[1];
            int idx = Arrays.binarySearch(tails, 0, len, h);
            if (idx < 0) idx = -(idx + 1);
            if (idx == len) ++len;
            tails[idx] = h;
        }
        return len;
    }
}
