class Solution {
    public int countTriplets(int[] arr) {
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, 1);
        int cur = 0;
        int n = arr.length;
        int ans = 0;
        for(int j = 0; j < n; ++j) {
            cur ^= arr[j];
            int temp = cur;
            for(int k = j + 1; k < n; ++k) {
                temp ^= arr[k];
                int b = temp ^ cur;
                int need = cur ^ b;
                ans += seen.getOrDefault(need, 0);
            }
            seen.put(cur, seen.getOrDefault(cur, 0) + 1);
        }
        return ans;
    }
}
