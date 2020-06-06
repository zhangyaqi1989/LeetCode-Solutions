class Solution {
    public int sumOfDigits(int[] A) {
        int mn = Integer.MAX_VALUE;
        for(int num : A) mn = Math.min(mn, num);
        int cnt = 0;
        while(mn != 0) {
            cnt += mn % 10;
            mn /= 10;
        }
        return cnt % 2 == 1 ? 0 : 1;
    }
}
