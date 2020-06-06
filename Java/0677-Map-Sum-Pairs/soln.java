class MapSum {
    private Map<String, Integer> data;

    /** Initialize your data structure here. */
    public MapSum() {
        data = new HashMap<>();
    }
    
    public void insert(String key, int val) {
        data.put(key, val);
    }
    
    public int sum(String prefix) {
        int ans = 0;
        for (String key : data.keySet()) {
            if (key.startsWith(prefix)) ans += data.get(key);
        }
        return ans;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
