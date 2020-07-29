class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int points = 0;
        int diet = 0, n = calories.length;
        for(int i = 0; i < n; ++i) {
            diet += calories[i];
            if (i >= k) diet -= calories[i - k];
            if (i < k - 1) continue;
            if (diet > upper) ++points;
            else if (diet < lower) --points;
        }
        return points;
    }
}
