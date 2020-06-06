class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<vector<int>> tree(10, vector<int>(20, -1));
        for(int num : nums) {
            int V = num % 10;
            num /= 10;
            int P = num % 10;
            num /= 10;
            int D = num % 10;
            tree[D][P] = V;
        }
        int ans = 0;
        dfs(tree, 1, 1, 0, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>> & tree, int D, int P, int path, int & ans) {
        if (tree[D + 1][P * 2 - 1] == -1 && tree[D + 1][P * 2] == -1) {
            ans += path + tree[D][P];
        } else {
            if (tree[D + 1][P * 2 - 1] != -1) {
                dfs(tree, D + 1, P * 2 - 1, path + tree[D][P], ans);
            }
            if (tree[D + 1][P * 2] != -1) {
                dfs(tree, D + 1, P * 2, path + tree[D][P], ans);
            }
        }
    }
};
