class Solution {
    public int countElements(int[] arr) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : arr) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        int cnt = 0;
        for(int key : counter.keySet()) {
            if(counter.containsKey(key + 1)) cnt += counter.get(key);
        }
        return cnt;
    }
}
