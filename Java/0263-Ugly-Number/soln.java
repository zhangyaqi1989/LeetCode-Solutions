class Solution {
    public boolean isUgly(int num) {
        if (num <= 0) return false;
        int [] factors = {2, 3, 5};
        for(int f : factors) {
            while (num % f == 0) num /= f;
        }
        return num == 1;
    }
}
