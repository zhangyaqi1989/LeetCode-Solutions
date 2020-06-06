class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int N = grid.size();
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(N, vector<int>(N, -1)));
        return max(0, helper(0, 0, 0, grid, memo));
    }
    
private:
    int helper(int r1, int c1, int r2, const vector<vector<int>>& grid, vector<vector<vector<int>>> & memo) {
        int c2 = r1 + c1 - r2;
        const int N = grid.size();
        if(r1 == N || c1 == N || r2 == N || c2 == N || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;
        else if (r1 == N - 1 && c1 == N - 1) return grid[N - 1][N - 1];
        else if (memo[r1][c1][r2] != -1) return memo[r1][c1][r2];
        else {
            int ans = grid[r1][c1] + (r1 != r2) * grid[r2][c2];
            ans += max(max(helper(r1 + 1, c1, r2 + 1, grid, memo), helper(r1, c1 + 1, r2 + 1, grid, memo)), 
                       max(helper(r1 + 1, c1, r2, grid, memo), helper(r1, c1 + 1, r2, grid, memo)));
            memo[r1][c1][r2] = ans;
            return ans;
        }
    }
};
