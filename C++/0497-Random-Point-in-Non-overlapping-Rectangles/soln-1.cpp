class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int acc = 0;
        for(auto & rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            acc += (y2 - y1 + 1) * (x2 - x1 + 1);
            areas.push_back(acc);
        }
    }
    
    vector<int> pick() {
        int mx = areas.back();
        int r = random() % mx + 1;
        int idx = lower_bound(areas.begin(), areas.end(), r) - areas.begin();
        auto & rect = rects[idx];
        int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
        int x = random() % (x2 - x1 + 1) + x1;
        int y = random() % (y2 - y1 + 1) + y1;
        return {x, y};
    }
private:
    vector<vector<int>> rects;
    vector<int> areas;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
