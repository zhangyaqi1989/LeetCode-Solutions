class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> counter;
        int m = mat.size();
        for(auto & row : mat) {
            for(auto num : row) {
                ++counter[num];
                if (counter[num] == m) return num;
            }
        }
        return -1;
    }
};
