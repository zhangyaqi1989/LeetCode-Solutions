class Solution {
    public boolean reorderedPowerOf2(int N) {
        String N_str = Integer.toString(N);
        int[] digits = new int[10];
        for(char ch : N_str.toCharArray()) {
            ++digits[ch - '0'];
        }
        for(int i = 0; i < 31; ++i) {
            int num = (1 << i);
            // System.out.println(i);
            String str = Integer.toString(num);
            int [] temp = new int[10];
            for(char ch : str.toCharArray()) {
                ++temp[ch - '0'];
            }
            boolean valid = true;
            for(int j = 0; j < 10; ++j) {
                if (temp[j] != digits[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
        return false;
    }
}
