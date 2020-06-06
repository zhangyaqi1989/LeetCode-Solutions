class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> s(A.begin(), A.end());
        for(auto b : B)
            if (s.count(b + diff))
                return {b + diff, b};
    }
};