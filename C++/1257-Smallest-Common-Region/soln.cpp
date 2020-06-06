class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // lowest common ancestor
        unordered_map<string, string> parents;
        for(const vector<string> & region : regions) {
            const int kN = region.size();
            for(int i = 1; i < kN; ++i) {
                parents[region[i]] = region[0];
            }
        }
        unordered_set<string> ancestors;
        while (true) {
            ancestors.insert(region1);
            auto it = parents.find(region1);
            if (it == parents.end()) break;
            region1 = it->second;
        }
        while (true) {
            if (ancestors.count(region2)) return region2;
            region2 = parents[region2];
        }
        return "";
    }
};
