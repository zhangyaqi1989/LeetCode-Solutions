class MyCalendarThree {
    public Map<Integer, Integer> times;

    public MyCalendarThree() {
        times = new TreeMap<>();
    }
    
    public int book(int start, int end) {
        times.put(start, times.getOrDefault(start, 0) + 1);
        times.put(end, times.getOrDefault(end, 0) - 1);
        int mx = 0, cur = 0;
        for(int change : times.values()) {
            cur += change;
            mx = Math.max(mx, cur);
        }
        return mx;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
