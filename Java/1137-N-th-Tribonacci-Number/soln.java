class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 1;
        int a = 0, b = 1, c = 1;
        for(int i = 3; i <= n; ++i) {
            int new_c = a + b + c;
            a = b;
            b = c;
            c = new_c;
        }
        return c;
    }
}
