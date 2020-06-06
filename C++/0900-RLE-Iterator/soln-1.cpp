class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        this->A = A;
        i = 0;
    }
    
    int next(int n) {
        int val = -1;
        while (n) {
            update();
            if (i < A.size()) {
                int used = min(n, A[i]);
                val = A[i + 1];
                A[i] -= used;
                n -= used;
            } else {
                val = -1;
                break;
            }
        }
        return val;
    }
    
private:
    int i;
    vector<int> A;
    
    void update() {
        while (i < A.size() && A[i] == 0) {
            i += 2;
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
