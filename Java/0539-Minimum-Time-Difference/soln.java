class Solution {
    public int findMinDifference(List<String> timePoints) {
        if (timePoints.size() > 1440) return 0;
        List<Integer> times = new ArrayList<>();
        for(String time : timePoints) {
            int h = Integer.parseInt(time.substring(0, 2));
            int m = Integer.parseInt(time.substring(3));
            times.add(h * 60 + m);
        }
        Collections.sort(times);
        int n = times.size();
        int ans = times.get(0) + 1440 - times.get(n - 1);
        for(int i = 0; i < n - 1; ++i) {
            ans = Math.min(ans, times.get(i + 1) - times.get(i));
        }
        return ans;
    }
}
