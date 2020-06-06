class Solution {
    public int maximumSwap(int num) {
        List<Integer> digits = new ArrayList<>();
        do {
            digits.add(num % 10);
            num /= 10;
        } while (num != 0);
        final int kN = digits.size();
        for(int i = kN - 1; i >= 0; --i) {
            int cand = digits.get(i);
            int cand_idx = -1;
            for(int j = 0; j < i; ++j) {
                if (digits.get(j) > cand) {
                    cand = digits.get(j);
                    cand_idx = j;
                }
            }
            if (cand > digits.get(i)) {
                int temp = digits.get(i);
                digits.set(i, digits.get(cand_idx));
                digits.set(cand_idx, temp);
                break;
            }
        }
        int ans = 0;
        for(int i = kN - 1; i >= 0; --i) {
            ans = ans * 10 + digits.get(i);
        }
        return ans;
    }
}
