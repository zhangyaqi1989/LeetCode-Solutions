class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(int l : left) {
            ans = max(ans, l);
        }
        for(int r : right) {
            ans = max(ans, n - r);
        }
        return ans;
    }
};
