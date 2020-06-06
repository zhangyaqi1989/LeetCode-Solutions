class Solution {
    public int numShineMoment(int[] light) {
        TreeSet<Integer> left = new TreeSet<>();
        int n = light.length;
        for(int i = 1; i <= n; ++i) left.add(i);
        int right = -1;
        int cnt = 0;
        for(int idx : light) {
            left.remove(idx);
            right = Math.max(right, idx);
            if (left.isEmpty() || left.first() > right) ++cnt;
        }
        return cnt;
    }
}
