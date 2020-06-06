class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int total = accumulate(A.begin(), A.end(), 0);
        int n = A.size(), m = n / 2;
        bool possible = false;
        for(int i = 1; i <= m && !possible; ++i) {
            if (total * i % n == 0) possible = true;
        }
        if (!possible) return false;
        vector<unordered_set<int>> sums(m + 1);
        sums[0].insert(0);
        for(int num : A) {
            for(int i = m; i >= 1; --i) {
                for(int item : sums[i - 1]) sums[i].insert(item + num);
            }
        }
        for(int i = 1; i <= m; ++i) {
            if (total * i % n == 0 && sums[i].find(total * i / n) != sums[i].end()) return true;
        }
        return false;
    }
};
