class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n));
        int cur = 1;
        int r = 0, c = 0;
        int dr = 0, dc = 1;
        while (cur <= n * n) 
        {
            grid[r][c] = cur;
            if (r + dr < 0 || r + dr >= n || c + dc < 0 || c + dc >= n || grid[r + dr][c + dc] > 0)
            {
                // dr, dc = dc, -dr
                int temp = dr;
                dr = dc;
                dc = -temp;
            }
            r += dr;
            c += dc;
            cur += 1;
        }
        return grid;
    }
};