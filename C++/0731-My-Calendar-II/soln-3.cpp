class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++times_[start];
        --times_[end];
        int cnt = 0;
        for(const auto & p : times_) {
            cnt += p.second;
            if (cnt > 2) {
                --times_[start];
                ++times_[end];
                return false;
            }
        }
        return true;
    }
    
private:
    map<int, int> times_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
