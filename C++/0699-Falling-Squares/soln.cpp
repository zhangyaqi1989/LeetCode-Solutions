struct Interval {
    int start;
    int end;
    int height;
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> heights;
        vector<Interval> intervals;
        int mx_height = 0;
        for(const auto & pos : positions) {
            int left = pos[0];
            int side = pos[1];
            int cur_height = InsertInterval(left, side, &intervals);
            mx_height = max(mx_height, cur_height);
            heights.push_back(mx_height);
        }
        return heights;
    }
    
private:
    int InsertInterval(int left, int side, vector<Interval> * intervals) {
        int start = left;
        int end = left + side;
        int bottom = 0;
        for(auto it = intervals->begin(); it != intervals->end(); ++it) {
            if (it->end <= start || end <= it->start) continue;
            bottom = max(bottom, it->height);
        }
        int height = bottom + side;
        intervals->push_back({start, end, height});
        return height;
    }
};
