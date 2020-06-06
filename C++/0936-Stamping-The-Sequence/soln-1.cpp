class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if (stamp[0] != target[0] || stamp.back() != target.back()) return {};
        const int N = target.length();
        const int M = stamp.length();
        vector<int> ans;
        int cnt = 0;
        for(int k = 0; k < N * 10; ++k) {
            if (cnt == N) {
                reverse(ans.begin(), ans.end());
                return ans;
            }
            bool processed = false;
            for(int i = 0; i < N - M + 1; ++i) {
                bool valid = true;
                int removed = 0;
                for(int j = 0; j < M; ++j) {
                    if (stamp[j] == target[i + j] || target[i + j] == '?') {
                        removed += target[i + j] != '?';
                    } else {
                        valid = false;
                        break;
                    }
                }
                if( valid && removed) {
                    for(int j = 0; j < M; ++j) target[i + j] = '?';
                    cnt += removed;
                    ans.push_back(i);
                    processed = true;
                    break;
                }
            }
            if (!processed) return {};
        }
        return {};
    }
};
