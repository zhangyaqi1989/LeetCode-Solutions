class MyCalendarTwo {
    map<int, int> times;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        times[start]++;
        times[end]--;
        int booked = 0;
        for(auto &item : times) {
            booked += item.second;
            if (booked == 3) {
                times[start]--;
                times[end]++;
                return false;
            }
        }
        return true;
    }
};



/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */