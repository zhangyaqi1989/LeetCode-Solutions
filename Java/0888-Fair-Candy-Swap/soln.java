class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sa = 0, sb = 0;
        for(int num : A) sa += num;
        for(int num : B) sb += num;
        int diff = (sb - sa) / 2;
        Set<Integer> B_set = new HashSet<>();
        for(int num : B) B_set.add(num);
        for(int num : A) {
            if (B_set.contains(num + diff)) return new int[] {num, num + diff};
        }
        return new int[] {0, 0};
    }
}
