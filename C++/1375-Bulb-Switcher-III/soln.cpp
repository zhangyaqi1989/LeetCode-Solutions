class Solution {
public:
    int numShineMoment(vector<int>& light) {
        set<int> left;
        int n = light.size();
        for(int i = 1; i <= n; ++i) left.insert(i);
        int right = -1;
        int cnt = 0;
        for(int idx : light) {
            left.erase(idx);
            right = max(right, idx);
            if (left.empty() || (*left.begin()) > right) ++cnt;
        }
        return cnt;
    }
};
