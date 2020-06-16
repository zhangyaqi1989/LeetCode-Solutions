class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : arr) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        int ans = counter.size();
        List<Integer> cnts = new ArrayList<>();
        for(int cnt : counter.values()) cnts.add(cnt);
        Collections.sort(cnts);
        for(int cnt : cnts) {
            if(k >= cnt) {
                k -= cnt;
                --ans;
            } else break;
        }
        return ans;
    }
}
