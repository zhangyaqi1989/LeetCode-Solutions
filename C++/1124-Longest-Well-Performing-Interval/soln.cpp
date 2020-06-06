class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int acc = 0;
        unordered_map<int, int> memo;
        memo[0] = -1;
        int mx_len = 0;
        int n = hours.size();
        for(int i = 0; i < n; ++i) {
            int hour = hours[i];
            if (hour > 8) ++acc;
            else --acc;
            if (acc > 0) mx_len = i + 1;
            if (memo.find(acc) == memo.end()) memo[acc] = i;
            auto it = memo.find(acc - 1);
            if (it != memo.end()) mx_len = max(mx_len, i - it->second);
        }
        return mx_len;
    }
};
