class Solution {
    public int minBuildTime(int[] blocks, int split) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int num : blocks) pq.offer(num);
        while (pq.size() > 1) {
            int x = pq.poll(), y = pq.poll();
            pq.offer(y + split);
        }
        return pq.poll();
    }
}
