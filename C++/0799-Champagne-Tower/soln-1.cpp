class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> glasses(100, 0.0);
        glasses[0] = poured;
        for(int row = 1; row <= query_row; ++row) {
            for(int j = row; j >= 0; --j) {
                glasses[j] = max(0.0, glasses[j] - 1) / 2;
                if (j > 0) glasses[j] += max(0.0, glasses[j - 1] - 1) / 2;
            }
        }
        return min(1.0, glasses[query_glass]);
    }
};
