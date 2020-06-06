class ExamRoom {
    set<int> occupy;
    int N;
public:
    ExamRoom(int N): N(N){
        occupy.clear();
    }
    
    int seat() {
        if (occupy.empty()) {
            occupy.insert(0);
            return 0;
        } else {
            int ans = 0;
            int dist = *occupy.begin();
            int cnt = 0;
            for(auto it = occupy.begin(); it != prev(occupy.end()); ++it) {
                int a = *it;
                int b = *next(it, 1);
                if ((b - a) / 2 > dist) {
                    ans = a + (b - a) / 2;
                    dist = (b - a) / 2;
                }
                ++cnt;
            }
            if (N - 1 - *occupy.rbegin() > dist) {
                ans = N - 1;
            }
            occupy.insert(ans);
            return ans;
        }
    }
    
    void leave(int p) {
        occupy.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
