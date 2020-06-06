class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        this->matrix = matrix;
        m = matrix.size() + 1;
        n = matrix[0].size() + 1;
        tree.assign(m, vector<int>(n, 0));
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                add(i, j, matrix[i - 1][j - 1]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        add(row + 1, col + 1, val - matrix[row][col]);
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2 + 1, col2 + 1) + sum(row1, col1) - sum(row1, col2 + 1) - sum(row2 + 1, col1);
    }

private:
    vector<vector<int>> tree;
    vector<vector<int>> matrix;
    int m, n;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int i, int j, int val) {
        if(val != 0) {
            for(int r = i; r < m; r += lowbit(r)) {
                for(int c = j; c < n; c += lowbit(c)) {
                    tree[r][c] += val;
                }
            }
        }
    }
    
    int sum(int i, int j) {
        int ans = 0;
        for(int r = i; r > 0; r -= lowbit(r)) {
            for(int c = j; c > 0; c -= lowbit(c)) {
                ans += tree[r][c];
            }
        }
        return ans;
    }
    
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
