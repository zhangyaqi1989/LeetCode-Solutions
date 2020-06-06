class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        unordered_set<int> black(blacklist.begin(), blacklist.end());
        m = N - black.size();
        for(const auto & num : black) {
            if (num < m) {
                --N;
                while(black.count(N)) --N;
                idx_map_[num] = N;
            }
        }
    }
    
    int pick() {
        int idx = rand() % m;
        auto it = idx_map_.find(idx);
        if(it == idx_map_.end()) return idx;
        else return it->second;
    }
private:
    unordered_map<int, int> idx_map_;
    int m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
