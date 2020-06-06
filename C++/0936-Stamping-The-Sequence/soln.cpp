class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if (target[0] != stamp[0] || target.back() != stamp.back()) return {};
        vector<int> ans;
        int step = 0, n = target.length(), m = stamp.length();
        string goal(target.length(), '?');
        while (step <= n) {
            for(int i = 0; i < n - m + 1; ++i) {
                if (match(stamp, target, i) > 0) {
                    fill(target.begin() + i, target.begin() + i + m, '?');
                    ans.push_back(i);
                }
            }
            ++step;
            if (target == goal) {
                reverse(ans.begin(), ans.end());
                return ans;
            }
        }
        return {};
    }
    
    int match(string & stamp, string & target, int start) {
        int cnt = 0, n = stamp.length();
        for(int i = 0; i < n; ++i) {
            if (target[i + start] != '?') {
                if (target[i + start] != stamp[i]) return 0;
                ++cnt;
            } 
        }
        return cnt;
    }
};
