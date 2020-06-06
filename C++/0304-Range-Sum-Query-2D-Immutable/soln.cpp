class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        const int m = matrix.size(), n = matrix[0].size();
        prefix_.assign(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                prefix_[i][j] = matrix[i - 1][j - 1] + prefix_[i - 1][j] + prefix_[i][j - 1] - prefix_[i - 1][j - 1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_[row2 + 1][col2 + 1] + prefix_[row1][col1] - prefix_[row2 + 1][col1] - prefix_[row1][col2 + 1];
    }
    
private:
    vector<vector<int>> prefix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
