class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] counter = new int[501];
        for(int t : time) ++counter[t];
        int ans = 0;
        for(int t1 = 1; t1 <= 500; ++t1) {
            for(int t2 = t1; t2 <= 500; ++t2) {
                if (counter[t1] > 0 && counter[t1] > 0 && (t1 + t2) % 60 == 0) {
                    if (t1 == t2) ans += counter[t1] * (counter[t1] - 1) / 2;
                    else ans += counter[t1] * counter[t2];
                }
            }
        } 
        return ans;
    }
}
