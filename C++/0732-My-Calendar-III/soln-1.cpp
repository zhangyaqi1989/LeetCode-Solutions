class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start] ++;
        m[end] --;
        int res = 0;
        int cnt = 0;
        for(auto & pair : m) {
            cnt += pair.second;
            if (cnt > res)
                res = cnt;
        }
        return res;
    }
    
    map<int, int> m;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */