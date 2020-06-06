class Solution {
    // int n_rows;
    int n_cols;
    int n; // number of elements in the matrix
    unordered_set<int> fliped;
public:
    Solution(int n_rows, int n_cols) {
        // this->n_rows = n_rows;
        this->n_cols = n_cols;
        this->n = n_rows * n_cols;
        fliped.clear();
    }
    
    vector<int> flip() {
        int num;
        do {
            num = rand() % n;
        } while (fliped.find(num) != fliped.end());
        fliped.insert(num);
        return {num / n_cols, num % n_cols};
    }
    
    void reset() {
        fliped.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
