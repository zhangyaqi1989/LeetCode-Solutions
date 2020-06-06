class MyHashMap {
    
    private static final int SIZE = 1337;
    List<int []> [] nums;
    
    private int getIdx(int key) {
        return key % SIZE;
    }

    /** Initialize your data structure here. */
    public MyHashMap() {
        nums = new ArrayList[SIZE];
        for(int i = 0; i < SIZE; ++i) {
            nums[i] = new ArrayList<>();
        }
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        int idx = getIdx(key);
        boolean find = false;
        for(int [] pair : nums[idx]) {
            if(pair[0] == key) {
                pair[1] = value;
                find = true;
            }
        }
        if(!find) nums[idx].add(new int [] {key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int idx = getIdx(key);
        for(int [] pair : nums[idx]) {
            if (pair[0] == key) return pair[1];
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int idx = getIdx(key);
        int n = nums[idx].size();
        for(int i = 0; i < n; ++i) {
            if (nums[idx].get(i)[0] == key) {
                nums[idx].remove(i);
                break;
            }
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
