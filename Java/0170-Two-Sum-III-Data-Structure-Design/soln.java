class TwoSum {
    Map<Integer, Integer> m;

    /** Initialize your data structure here. */
    public TwoSum() {
        m = new HashMap<>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        m.put(number, m.getOrDefault(number, 0) + 1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for(int num : m.keySet()) {
            // System.out.println(num);
            int cnt = (num == value - num ? 1 : 0);
            // System.out.println(cnt);
            if (m.get(value - num) != null && m.get(value - num) > cnt) return true;
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
