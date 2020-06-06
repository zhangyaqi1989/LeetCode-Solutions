class Solution {
    public int findNthDigit(int n) {
        long unit = 9;
        int d = 1;
        while (n > 0) {
            long num = unit * d;
            if (n > num) {
                n -= num;
            } else {
                --n;
                int q = n / d;
                int r = n % d;
                String s = Integer.toString((int) Math.pow(10, d - 1) + q);
                return s.charAt(r) - '0';
            }
            ++d;
            unit *= 10;
        }
        return 0;
    }
}
