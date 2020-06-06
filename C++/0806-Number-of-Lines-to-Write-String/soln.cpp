class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1, cur = 0;
        for(char ch : S) {
            int width = widths[ch - 'a'];
            if (cur + width > 100) {
                ++lines;
                cur = width;
            } else {
                cur += width;
            }
        }
        return {lines, cur};
    }
};
