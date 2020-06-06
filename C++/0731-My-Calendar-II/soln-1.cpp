class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int s, e;
        for(auto & p : twice) {
            tie(s, e) = p;
            if (!(end <= s || e <= start)) return false;
        }
        vector<pair<int, int>> new_once;
        for(auto & p : once) {
            tie(s, e) = p;
            if(end <= s || e <= start) new_once.emplace_back(s, e);
            else {
                twice.emplace_back(max(s, start), min(e, end));
                new_once.emplace_back(min(s, start), max(s, start));
                new_once.emplace_back(min(e, end), max(e, end));
            }
        }
        new_once.emplace_back(start, end);
        swap(once, new_once);
        return true;
    }
    
private:
    vector<pair<int, int>> twice, once;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
