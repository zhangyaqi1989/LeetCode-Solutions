class RandomizedSet {
    
    private List<Integer> vals;
    private Map<Integer, Integer> idxes;
    private Random rand;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        vals = new ArrayList<>();
        idxes = new HashMap<>();
        rand = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (!idxes.containsKey(val)) {
            idxes.put(val, vals.size());
            vals.add(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (idxes.containsKey(val)) {
            int idx = idxes.get(val);
            int last = vals.get(vals.size() - 1);
            vals.remove(vals.size() - 1);
            idxes.remove(val);
            if (last != val) {
                vals.set(idx, last);
                idxes.put(last, idx);
            }
            return true;
            
        }
        return false;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        int idx = rand.nextInt(vals.size());
        return vals.get(idx);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
