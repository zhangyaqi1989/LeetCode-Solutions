class MyCalendar {
    vector<pair<int, int>> times;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool valid = true;
        for (auto & it : times) {
            // cout << it.first << " " << it.second << endl;
            if (!(end <= it.first || it.second <= start)) {
                valid = false;
                break;
            }
        }
        if (valid) times.push_back(make_pair(start, end));
        return valid;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
