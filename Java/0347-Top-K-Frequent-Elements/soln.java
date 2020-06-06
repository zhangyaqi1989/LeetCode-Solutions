class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b)->(b.getValue() - a.getValue()));
        List<Integer> ans = new ArrayList<>();
        int n = counter.size();
        for(Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            pq.offer(entry);
            if (pq.size() > n - k) {
                ans.add(pq.poll().getKey());
            }
        }
        return ans;
    }
}
