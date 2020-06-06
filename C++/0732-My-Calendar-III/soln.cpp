class MyCalendarThree {
    map<int, int> cal;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        cal[start]++;
        cal[end]--;
        int ans = 0, cur = 0;
        for(auto item : cal)
        {
            cur += item.second;
            ans = max(ans, cur);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */