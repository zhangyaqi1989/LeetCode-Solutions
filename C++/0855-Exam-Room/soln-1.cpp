class ExamRoom {
public:
    ExamRoom(int N): N_(N) {
        
    }
    
    int seat() {
        if (seats_.empty()) {
            seats_.insert(0);
            return 0;
        }
        int pos = 0;
        int max_distance = *seats_.cbegin();
        for(auto it = seats_.cbegin(); it != seats_.cend(); ++it) {
            if (next(it) != seats_.cend()) {
                int distance = (*next(it) - *it) / 2;
                if (distance > max_distance) {
                    max_distance = distance;
                    pos = *it + max_distance;
                }
            } else {
                int distance = N_ - 1 - *it;
                if (distance > max_distance) {
                    max_distance = distance;
                    pos = N_ - 1;
                }
            }
        }
        seats_.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        seats_.erase(p);
    }
    
private:
    set<int> seats_;
    int N_;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
