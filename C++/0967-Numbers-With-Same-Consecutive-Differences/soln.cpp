class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int start = N == 1 ? 0 : 1;
        vector<int> ans;
        vector<int> sub;
        for(int i = start; i < 10; ++i) {
            sub.push_back(i);
            helper(N, K, sub, ans);
            sub.pop_back();
        }
        return ans;
    }
    
    void helper(int N, int K, vector<int> & sub, vector<int> & ans) {
        if (sub.size() == N) {
            int num = 0;
            for(int d : sub) num = num * 10 + d;
            ans.push_back(num);
        } else {
            int end_num = sub.back();
            if (0 <= end_num + K && end_num + K < 10) {
                sub.push_back(end_num + K);
                helper(N, K, sub, ans);
                sub.pop_back();
            }
            if (K != 0) {
                if (0 <= end_num - K && end_num - K < 10) {
                    sub.push_back(end_num - K);
                    helper(N, K, sub, ans);
                    sub.pop_back();
                }
            }
        }
    }
};
