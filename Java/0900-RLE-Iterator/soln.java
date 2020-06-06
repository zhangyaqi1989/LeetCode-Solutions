class RLEIterator {

    public RLEIterator(int[] A) {
        this.A = A.clone();
        i = 0;
    }
    
    public int next(int n) {
        int val = -1;
        while (n > 0) {
            update();
            if (i < A.length) {
                int used = Math.min(n, A[i]);
                A[i] -= used;
                n -= used;
                val = A[i + 1];
            } else {
                val = -1;
                break;
            }
        }
        return val;
    }
    
    private int i;
    private int [] A;
    private void update() {
        while (i < A.length && A[i] == 0) i += 2;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
