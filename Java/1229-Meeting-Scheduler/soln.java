class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        Arrays.sort(slots1, (a, b) -> (a[0] - b[0]));
        Arrays.sort(slots2, (a, b) -> (a[0] - b[0]));
        int n1 = slots1.length, n2 = slots2.length;
        int j = 0;
        for(int i = 0; i < n1; ++i) {
            while (j < n2 && slots2[j][1] < slots1[i][0]) ++j;
            while (j < n2 && slots2[j][0] <= slots1[i][1]) {
                int s = Math.max(slots1[i][0], slots2[j][0]);
                int e = Math.min(slots1[i][1], slots2[j][1]);
                if (e - s >= duration) return Arrays.asList(s, s + duration);
                ++j;
            }
            if (j > 0) --j;
        }
        return Arrays.asList();
    }
}
