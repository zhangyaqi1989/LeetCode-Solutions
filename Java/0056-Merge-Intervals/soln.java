class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));
        List<int []> merged = new ArrayList<>();
        for(int [] inter : intervals) {
            if (merged.isEmpty() || inter[0] > merged.get(merged.size() - 1)[1]) {
                merged.add(new int[] {inter[0], inter[1]});
            } else {
                merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], inter[1]);
            }
        }
        return merged.toArray(new int[0][]);
    }
}
