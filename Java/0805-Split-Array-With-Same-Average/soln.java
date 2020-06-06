class Solution {
    public boolean splitArraySameAverage(int[] A) {
        int total = 0, n = A.length, m = n / 2;
        for(int num : A) total += num;
        boolean possible = false;
        for(int i = 1; i <= m && !possible; ++i) {
            if (total * i % n == 0) possible = true;
        }
        if (!possible) return false;
        Set<Integer> [] sums = new Set[m + 1];
        for(int i = 0; i < m + 1; ++i) sums[i] = new HashSet<>();
        sums[0].add(0);
        for(int num : A) {
            for(int i = m; i >= 1; --i) {
                for(int item : sums[i - 1]) sums[i].add(item + num);
            }
        }
        for(int i = 1; i <= m; ++i) {
            if (total * i % n == 0 && sums[i].contains(total * i / n)) return true;
        }
        return false;
    }
}
