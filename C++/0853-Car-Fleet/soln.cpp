class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs;
        pairs.reserve(n);
        for(int i = 0; i < n; ++i) {
            pairs.emplace_back(target - position[i], speed[i]);
        }
        sort(pairs.begin(), pairs.end());
        int cnt = 0;
        double time = -1.0;
        for(int i = 0; i < n; ++i) {
            double temp = (double) pairs[i].first / pairs[i].second;
            if (temp > time) {
                time = temp;
                ++cnt;
            }
        }
        return cnt;
    }
};
