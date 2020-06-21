class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> drys;
        vector<int> ans;
        map<int, deque<int>> levels;
        // int valid_lake = -1;
        const int kN = rains.size();
        for(int i = 0; i < kN; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                // no rain
                drys.insert(i);
                ans.push_back(-2);
            } else {
                ans.push_back(-1);
                // if(valid_lake == -1) valid_lake = lake;
                levels[lake].push_back(i);
                auto it = levels.find(lake);
                if((it->second).size() >= 2) {
                    int day = it->second.front();
                    // find the earliest dry that > day
                    auto dry_it = drys.lower_bound(day);
                    if (dry_it == drys.end()) {
                        return {};
                    } else {
                        ans[*dry_it] = lake;
                        drys.erase(dry_it);
                        (it->second).pop_front();
                    }
                }
            }
        }
        for(int i = 0; i < kN; ++i) {
            if(ans[i] == -2) ans[i] = 1;
        }
        return ans;
    }
};
