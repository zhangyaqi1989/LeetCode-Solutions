class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa = accumulate(A.begin(), A.end(), 0);
        int sb = accumulate(B.begin(), B.end(), 0);
        int diff = (sb - sa) / 2;
        unordered_set<int> B_set(B.begin(), B.end());
        for(int num : A) {
            if (B_set.count(num + diff)) return {num, num + diff};
        }
        return {};
    }
};
