class Solution {
    public int[] getNoZeroIntegers(int n) {
        Random r = new Random();
        while (true) {
            int a = r.nextInt(n);
            int b = n - a;
            if (IsNoZeroIntegers(a) && IsNoZeroIntegers(b)) return new int[]{a, b};
        }
    }
    
    private boolean IsNoZeroIntegers(int num) {
        if (num <= 0) return false;
        do {
            if (num % 10 == 0) return false;
            num /= 10;
        } while (num != 0);
        return true;
    }
}
