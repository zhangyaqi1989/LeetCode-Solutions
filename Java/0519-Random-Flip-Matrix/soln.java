class Solution {
    public Set<Integer> flipped;
    public int n;
    public int n_cols;

    public Solution(int n_rows, int n_cols) {
        flipped = new HashSet<>();
        n = n_rows * n_cols;
        this.n_cols = n_cols;
    }
    
    public int[] flip() {
        Random r = new Random();
        int idx;
        do {
            idx = r.nextInt(n);
        } while (flipped.contains(idx));
        flipped.add(idx);
        return new int[] {idx / n_cols, idx % n_cols};
    }
    
    public void reset() {
        flipped.clear();
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
