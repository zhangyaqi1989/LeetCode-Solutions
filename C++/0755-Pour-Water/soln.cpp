class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        for(int i = 0; i < V; ++i) {
            int j = K;
            int left = K;
            while (j > 0 && heights[j - 1] <= heights[j]) {
                --j;
                if (heights[j] < heights[left]) left = j; 
            }
            j = left;
            if (j == K) {
                int right = K;
                while (j < n - 1 && heights[j + 1] <= heights[j]) {
                    ++j;
                    if (heights[j] < heights[right]) right = j;
                }
                j = right;
            }
            ++heights[j];
        }
        return heights;
    }
};
