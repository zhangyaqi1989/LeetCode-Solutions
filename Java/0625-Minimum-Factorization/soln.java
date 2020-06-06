class Solution {
    public int smallestFactorization(int a) {
        if (a <= 9) return a;
        List<Integer> digits = new ArrayList<>();
        for(int d = 9; d > 1; --d) {
            while (a % d == 0) {
                digits.add(d);
                a /= d;
                if (digits.size() > 10) return 0;
            }
            if (a == 1) break;
        }
        if (a > 1) return 0;
        int n = digits.size();
        long ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            ans = ans * 10 + digits.get(i);
            if (ans > Integer.MAX_VALUE) return 0;
        }
        return (int) ans;
    }
}
