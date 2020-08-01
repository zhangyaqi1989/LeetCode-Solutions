class Solution {
    public int minSwaps(int[] data) {
        int k = 0;
        for(int num : data) {
            if(num == 1) ++k;
        }
        int ones = 0, best = k;
        for(int i = 0; i < data.length; ++i) {
            if(data[i] == 1) ++ones;
            if(i >= k && data[i - k] == 1) --ones;
            if(i >= k - 1) {
                best = Math.min(best, k - ones);
            }
        }
        return best;
    }
}
