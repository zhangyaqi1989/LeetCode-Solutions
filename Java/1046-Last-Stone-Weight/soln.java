class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int stone : stones) pq.offer(-stone);
        while (pq.size() >= 2) {
            int a = -pq.poll();
            int b = -pq.poll();
            if (a != b) pq.offer(-Math.abs(b - a)); 
        }
        if (pq.size() == 1) return -pq.poll();
        return 0;
    }
}
