class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        count_ = n;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }
        return n - count_;
    }
    
    
private:
    int find(int x) {
        if(parents_.find(x) == parents_.end()) {
            parents_[x] = x;
            sizes_[x] = 1;
        }
        return parents_[x] == x ? x : parents_[x] = find(parents_[x]);
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            --count_;
            if (sizes_[rx] > sizes_[ry]) swap(rx, ry);
            parents_[rx] = ry;
            sizes_[ry] += sizes_[rx];
        }
    }
    unordered_map<int, int> parents_;
    unordered_map<int, int> sizes_;
    int count_;
};
