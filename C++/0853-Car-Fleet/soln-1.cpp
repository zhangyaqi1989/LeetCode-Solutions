class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // position
        const int kNCars = speed.size();
        vector<int> idxes(kNCars);
        iota(idxes.begin(), idxes.end(), 0);
        sort(idxes.begin(), idxes.end(), [&](int a, int b) {return position[a] > position[b];});
        int cnt = 0;
        double fastest_time = -1;
        for(int i = 0; i < kNCars; ++i) {
            int v = speed[idxes[i]], x = position[idxes[i]];
            double time = static_cast<double>(target - x) / v;
            if (time > fastest_time) {
                ++cnt;
                fastest_time = time;
            }
        }
        return cnt;
    }
};
