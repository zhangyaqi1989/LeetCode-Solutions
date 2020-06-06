class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int h = matrix.size(), w = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[h - 1][w - 1]) return false;
        int r = h - 1, c = 0;
        while(r >= 0 && c < w) {
            if(matrix[r][c] == target) return true;
            else if(target > matrix[r][c]) ++c;
            else --r;
        }
        return false;
        
    }
};
