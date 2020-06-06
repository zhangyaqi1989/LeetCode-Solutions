class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        int r = 0, c = 0;
        int dr = 0, dc = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        set<pair<int, int>> seen;
        for(int i = 0; i < m * n; i++)
        {
            ans.push_back(matrix[r][c]);
            seen.insert(make_pair(r, c));
            if (r + dr < 0 || r + dr >= m || c + dc < 0 || c + dc >= n || seen.find(make_pair(r + dr, c + dc)) != seen.end())
            {
                int temp = dr;
                dr = dc;
                dc = -temp;
            }
            r += dr;
            c += dc;
        }
        return ans;
    }
};