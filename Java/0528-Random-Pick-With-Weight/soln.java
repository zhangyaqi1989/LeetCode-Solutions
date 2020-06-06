class Solution {
    
    private int [] ws;
    private Random random;
    private int mx;

    public Solution(int[] w) {
        random = new Random();
        int n = w.length;
        ws = new int[n];
        int acc = 0;
        for(int i = 0; i < n; ++i) {
            acc += w[i];
            ws[i] = acc;
        }
        mx = acc;
    }
    
    public int pickIndex() {
        int rand_num = random.nextInt(mx) + 1;
        int idx = Arrays.binarySearch(ws, rand_num);
        if (idx < 0) idx = -(idx + 1);
        return idx;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
