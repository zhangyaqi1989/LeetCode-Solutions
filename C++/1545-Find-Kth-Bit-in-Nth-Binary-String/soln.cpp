class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> lst = {0};
        for(int i = 1; i < n; ++i) {
            int m = lst.size();
            lst.push_back(1);
            for(int j = m - 1; j >= 0; --j) {
                lst.push_back(1 - lst[j]);
            }
        }
        return '0' + lst[k - 1];
    }
};
