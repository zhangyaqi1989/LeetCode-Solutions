class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        A_ = move(A);
        idx_ = 0;
    }
    
    int next(int n) {
        while (n > 0) {
            if (idx_ == A_.size()) return -1;
            if (n <= A_[idx_]) {
                A_[idx_] -= n;
                return A_[idx_ + 1];
            } else {
                n -= A_[idx_];
                idx_ += 2;
            }
        }
        return -1;
    }
    
private:
    vector<int> A_;
    int idx_;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
