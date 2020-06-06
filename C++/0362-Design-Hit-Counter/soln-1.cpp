class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        gap_ = 300;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        records_.push_back(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!records_.empty() && timestamp - records_.front() >= gap_) records_.pop_front();
        return records_.size();
    }
    
private:
    deque<int> records_;
    int gap_;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
