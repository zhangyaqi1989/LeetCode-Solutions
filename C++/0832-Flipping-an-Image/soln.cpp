class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto & row : A) {
            int n = row.size();
            for(int i = 0; i < n / 2; ++i)
                swap(row[i], row[n - 1 - i]);
        }
        for (auto & row : A)
            for (auto & x : row)
                x ^= 1;
        return A;
    }
};