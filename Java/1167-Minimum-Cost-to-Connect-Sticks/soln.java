class Solution {
    public int connectSticks(int[] sticks) {
        PriorityQueue<Integer> pool = new PriorityQueue<>();
        for(int stick : sticks) pool.offer(stick);
        int ans = 0;
        while(pool.size() > 1) {
            int x = pool.poll(), y = pool.poll();
            ans += x + y;
            pool.offer(x + y);
        }
        return ans;
    }
}
