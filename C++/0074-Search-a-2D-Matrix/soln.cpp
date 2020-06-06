class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (target > matrix[mid / n][mid % n])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};