class MyCalendarThree {
    map<int, int> times;
public:
    MyCalendarThree() {
        times.clear();
    }
    
    int book(int start, int end) {
        ++times[start];
        --times[end];
        int mx = 0, cur = 0;
        for(auto & p : times) {
            mx = max(mx, cur += p.second);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
