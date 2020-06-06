class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++times_[start];
        --times_[end];
        int mx = 0;
        int cnt = 0;
        for(auto & p : times_) {
            cnt += p.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
    
private:
    map<int, int> times_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
