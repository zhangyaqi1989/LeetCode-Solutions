class MyHashSet {
    final static int N = 1337;
    List<Integer> [] nums;

    /** Initialize your data structure here. */
    public MyHashSet() {
        nums = new ArrayList[N];
        for(int i = 0; i < N; ++i) nums[i] = new ArrayList<>();
    }
    
    public void add(int key) {
        int idx = compute_idx(key);
        boolean is_in = false;
        for(int num : nums[idx]) {
            if (num == key) {
                is_in = true;
                break;
            }
        }
        if(!is_in) {
            nums[idx].add(key);
        }
    }
    
    public void remove(int key) {
        int idx = compute_idx(key);
        for(int j = 0; j < nums[idx].size(); ++j) {
            if (key == nums[idx].get(j)) {
                nums[idx].remove(j);
                break;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int idx = compute_idx(key);
        for(int num : nums[idx]) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }
    
    private int compute_idx(int key) {
        return key % N;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
