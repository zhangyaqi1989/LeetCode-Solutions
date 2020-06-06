class Solution {
    public boolean judgeSquareSum(int c) {
        int bound = (int) Math.sqrt(c);
        for(int a = 0; a <= bound; ++a) {
            int b2 = c - a * a;
            int b = (int) Math.sqrt(b2);
            if(b * b == b2) return true;
        }
        return false;
    }
}
