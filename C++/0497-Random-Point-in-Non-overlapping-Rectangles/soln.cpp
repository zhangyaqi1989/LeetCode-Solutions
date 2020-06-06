class Solution {
    vector<vector<int>> rects;
    vector<int> areas;
    int upper;
public:
    Solution(vector<vector<int>> rects) {
        this->rects = rects;
        for(auto rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            areas.push_back((x2 - x1 + 1) * (y2 - y1 + 1));
        }
        int n = areas.size();
        for(int i = 1; i < n; ++i) areas[i] += areas[i - 1];
        upper = areas.back();
    }
    
    vector<int> pick() {
        // rand an int [1, upper]
        int num = rand() % (upper) + 1;
        int idx = lower_bound(areas.begin(), areas.end(), num) - areas.begin();
        vector<int> & rect = rects[idx];
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
        return {rand() % (x2 - x1 + 1) + x1, rand() % (y2 - y1 + 1) + y1};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
