class MyCalendarTwo {
    private Map<Integer, Integer> times = new TreeMap<>();

    public MyCalendarTwo() {
        
    }
    
    public boolean book(int start, int end) {
        times.put(start, times.getOrDefault(start, 0) + 1);
        times.put(end, times.getOrDefault(end, 0) - 1);
        int nbooks = 0;
        for(int key : times.keySet()) {
            nbooks += times.get(key);
            if (nbooks == 3) {
                times.put(start, times.getOrDefault(start, 0) - 1);
                times.put(end, times.getOrDefault(end, 0) + 1);
                return false;
            }
        }
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
