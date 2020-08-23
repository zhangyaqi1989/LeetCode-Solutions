class Solution {
public:
    int minDays(int n) {
        memo_.clear();
        return solve(n);
    }

private:
    int solve(int left) {
        if(left <= 1) return left;
        auto it = memo_.find(left);
        if(it != memo_.end()) return it->second;
        int ans = 1 + min(left % 2 + solve(left / 2), left % 3 + solve(left / 3));
        memo_.insert({left, ans});
        return ans;
    }
    unordered_map<int, int> memo_;
};
