class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> counter(10001, 0);
        int m = mat.size();
        for(auto & row : mat) {
            for(auto num : row) {
                if (++counter[num] == m) return num;
            }
        }
        return -1;
    }
};
