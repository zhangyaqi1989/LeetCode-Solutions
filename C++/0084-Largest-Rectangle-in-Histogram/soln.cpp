class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int height = heights[i];
            while (s.size() && height <= heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.size() == 0 ? i : i - s.top() - 1;
                // cout << h << " " << w << endl;
                ans = max(ans, w * h);
                
            }
            s.push(i);
        }
        return ans;
    }
};