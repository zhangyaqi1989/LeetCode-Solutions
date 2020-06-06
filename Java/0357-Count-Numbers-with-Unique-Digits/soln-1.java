class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += count(i);
        return ans;
    }
    
    public int count(int w) {
        if (w == 1) return 10;
        if (w > 10) return 0;
        int ans = 9;
        int cand = 9;
        for(int i = 0; i < w - 1; ++i) ans *= (cand--);
        return ans;
    }
}
