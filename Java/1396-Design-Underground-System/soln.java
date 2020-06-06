class UndergroundSystem {
    private Map<Integer, Pair<String, Integer>> ids;
    private Map<String, Long> times;
    private Map<String, Integer> cnts;

    public UndergroundSystem() {
        ids = new HashMap<>();
        times = new HashMap<>();
        cnts = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        ids.put(id, new Pair(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> p = ids.get(id);
        String ticket = p.getKey() + " " + stationName;
        ids.remove(id);
        cnts.put(ticket, cnts.getOrDefault(ticket, 0) + 1);
        times.put(ticket, times.getOrDefault(ticket, 0L) + t - p.getValue());
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String ticket = startStation + " " + endStation;
        Long time = times.get(ticket);
        int cnt = cnts.get(ticket);
        return (double) time / cnt;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */
