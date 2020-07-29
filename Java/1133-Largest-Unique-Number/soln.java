class Solution {
    public int largestUniqueNumber(int[] A) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : A) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        int ans = -1;
        for(int key : counter.keySet()) {
            int cnt = counter.get(key);
            if(cnt == 1 && key > ans) {
                ans = key;
            }
        }
        return ans;
    }
}
