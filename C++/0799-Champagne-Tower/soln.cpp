class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> glasses(100, 0.0);
        glasses[0] = poured;
        for(int row = 1; row <= query_row; ++row) {
            vector<double> temp(100, 0.0);
            for(int j = 0; j < row + 1; ++j) {
                if (j == 0) {
                    temp[0] += (max(0.0, glasses[0] - 1)) / 2;
                } else if (j == row) {
                    temp[row] += (max(0.0, glasses[row - 1] - 1)) / 2;
                } else {
                    temp[j] += (max(0.0, glasses[j - 1] - 1) + max(0.0, glasses[j] - 1)) / 2;
                }
            }
            swap(glasses, temp);
        }
        return min(1.0, glasses[query_glass]);
    }
};
