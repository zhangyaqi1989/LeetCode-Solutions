class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        // gray code
        vector<int> codes = {0, 1};
        for(int i = 1; i < n; ++i) {
            const int sz = codes.size();
            for(int j = sz - 1; j >= 0; --j) {
                codes.push_back(codes[j] + (1 << i));
            }
        }
        auto mid = find(codes.begin(), codes.end(), start);
        rotate(codes.begin(), mid, codes.end());
        return codes;
    }
};
