class RecentCounter {
    
    public Queue<Integer> pings = new LinkedList<>();

    public RecentCounter() {
        
    }
    
    public int ping(int t) {
        pings.offer(t);
        while (!pings.isEmpty() && t - pings.peek() > 3000) {
            pings.poll();
        }
        return (int) pings.size();
    }
    
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
