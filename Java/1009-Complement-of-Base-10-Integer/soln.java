class Solution {
    public int bitwiseComplement(int N) {
        List<Integer> digits = new ArrayList<>();
        if (N == 0) {
            digits.add(1);
        } else {
            while (N > 0) {
                digits.add(1 - N % 2);
                N /= 2;
            }
        }
        int ans = 0, n = digits.size();
        for(int i = n - 1; i >= 0; --i) {
            ans = ans * 2 + digits.get(i);
        }
        return ans;
    }
}
