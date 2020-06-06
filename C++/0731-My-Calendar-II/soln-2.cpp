class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++times[start];
        --times[end];
        int nbooks = 0;
        for(auto & p : times) {
            nbooks += p.second;
            if (nbooks == 3) {
                --times[start];
                ++times[end];
                return false;
            }
        }
        return true;
    }
    
private:
    map<int, int> times;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
