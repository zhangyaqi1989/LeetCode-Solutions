class FirstUnique {
    private ArrayList<Integer> nums_;
    private HashMap<Integer, Integer> counter_;
    private int idx_;

    public FirstUnique(int[] nums) {
        nums_ = new ArrayList<>();
        counter_ = new HashMap<>();
        for(int num : nums) {
            int cnt = counter_.getOrDefault(num, 0);
            if(cnt == 0) {
                nums_.add(num);
            }
            counter_.put(num, cnt + 1);
        }
        idx_ = 0;
    }
    
    public int showFirstUnique() {
        while(idx_ < nums_.size() && counter_.get(nums_.get(idx_)) > 1) ++idx_;
        return idx_ < nums_.size() ? nums_.get(idx_) : -1;
    }
    
    public void add(int value) {
        counter_.put(value, counter_.getOrDefault(value, 0) + 1);
        nums_.add(value);
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */
