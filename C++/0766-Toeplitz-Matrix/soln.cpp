    static const auto __ = []() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return nullptr;
    }();


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (auto i = 0; i < m - 1; ++i)
            for (auto j = 0; j < n - 1; ++j)
                if (matrix[i + 1][j + 1] != matrix[i][j])
                    return false;
        return true;
    }
};