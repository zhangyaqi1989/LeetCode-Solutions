class Solution {
public:
    vector<int> constructRectangle(int area) {
        // width W should not be larger than the length L
        int upper = (int) sqrt(area);
        int w = upper;
        for(; w >= 1; --w) {
            if (area % w == 0) break;
        }
        return {area/w, w};
    }
};
