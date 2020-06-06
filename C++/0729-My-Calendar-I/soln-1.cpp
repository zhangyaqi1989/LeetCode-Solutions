class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = booked_.lower_bound(end); // it->first >= end
        if (it == booked_.begin()) {
            booked_.insert({start, end});
            return true;
        }
        it = prev(it);
        if (it->second <= start) {
            booked_.insert({start, end});
            return true;
        }
        return false;
    }
    
private:
    map<int, int> booked_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
