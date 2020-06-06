class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0, n = rating.size();
        for(int i = 0; i < n; ++i) {
            int less[2] = {}, greater[2] = {};
            for(int j = 0; j < n; ++j) {
                if (rating[i] > rating[j]) {
                    ++less[j > i];
                } else if (rating[i] < rating[j]) {
                    ++greater[j > i];
                }
            }
            cnt += less[0] * greater[1] + less[1] * greater[0];
        }
        return cnt;
    }
};
