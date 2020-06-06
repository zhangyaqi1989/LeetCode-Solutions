class Solution {
    public int monotoneIncreasingDigits(int N) {
        List<Integer> digits = new ArrayList<>();
        String str = Integer.toString(N);
        for(char ch : str.toCharArray()) digits.add(ch - '0');
        int n = digits.size();
        int end = n;
        for(int i = n - 1; i > 0; --i) {
            if (digits.get(i - 1) > digits.get(i)) {
                digits.set(i - 1, digits.get(i - 1) - 1);
                end = i;
            }
        }
        for(int i = end; i < n; ++i) digits.set(i, 9);
        int ans = 0;
        for(int digit : digits) ans = ans * 10 + digit;
        return ans;
    }
}
