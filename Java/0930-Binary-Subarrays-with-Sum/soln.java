class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, 1);
        int cur = 0;
        int cnt = 0;
        for(int num : A) {
            cur += num;
            cnt += seen.getOrDefault(cur - S, 0);
            seen.put(cur, seen.getOrDefault(cur, 0) + 1);
        }
        return cnt;
    }
}
