class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) return image;
        stack<pair<int, int>> s;
        s.push({sr, sc});
        int m = image.size(), n = image[0].size();
        while (s.size()) {
            pair<int, int> p = s.top();
            s.pop();
            int i = p.first, j = p.second;
            if(i >= 0 && i < m && j >= 0 && j < n && image[i][j] == color) {
                image[i][j] = newColor;
                s.push({i - 1, j});
                s.push({i + 1, j});
                s.push({i, j - 1});
                s.push({i, j + 1});
            }
        }
        return image;
        
    }
};