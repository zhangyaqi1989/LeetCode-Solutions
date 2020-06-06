class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int m) {
        int lo = 0;
        int n = flowerbed.length;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(flowerbed[i] != flowerbed[lo]) {
                int cnt = i - lo;
                if (flowerbed[lo] == 0) {
                    if (lo == 0) ans += cnt / 2;
                    else ans += (cnt - 1) / 2;
                }
                lo = i;
            }
        }
        if(flowerbed[lo] == 0) {
            int cnt = n - lo;
            if (lo == 0) ans += (cnt + 1) / 2; 
            else ans += cnt / 2;
        }
        return ans >= m;
    }
}
