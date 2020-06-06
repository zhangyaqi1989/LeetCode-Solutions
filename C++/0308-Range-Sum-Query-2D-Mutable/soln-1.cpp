class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        m_ = matrix.size() + 1;
        n_ = matrix[0].size() + 1;
        tree_.assign(m_, vector<int>(n_, 0));
        for(int i = 1; i < m_; ++i) {
            for(int j = 1; j < n_; ++j) {
                add(i, j, matrix[i - 1][j - 1]);
            }
        }
        nums_ = matrix;
    }
    
    void update(int row, int col, int val) {
        if (nums_[row][col] != val) {
            int delta = val - nums_[row][col];
            if (delta != 0) add(row + 1, col + 1, delta);
            nums_[row][col] = val;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2 + 1, col2 + 1) + query(row1, col1) - query(row1, col2 + 1) - query(row2 + 1, col1);
    }


private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int i, int j, int val) {
        int r = i;
        while (r < m_) {
            int c = j;
            while (c < n_) {
                tree_[r][c] += val;
                c += lowbit(c);
            }
            r += lowbit(r);
        }
    }
    
    int query(int i, int j) {
        int r = i;
        int ans = 0;
        while (r > 0) {
            int c = j;
            while (c > 0) {
                ans += tree_[r][c];
                c -= lowbit(c);
            }
            r -= lowbit(r);
        }
        return ans;
    }

    vector<vector<int>> tree_;
    int m_;
    int n_;
    vector<vector<int>> nums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
