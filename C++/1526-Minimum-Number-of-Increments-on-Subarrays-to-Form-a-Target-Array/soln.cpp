class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        int pre = target[0];
        const int kN = target.size();
        for(int i = 1; i < kN; ++i) {
            ans += max(0, target[i] - pre);
            pre = target[i];
        }
        return ans;
    }
};
