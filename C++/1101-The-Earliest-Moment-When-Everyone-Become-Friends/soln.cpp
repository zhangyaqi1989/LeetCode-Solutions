class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(), logs.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] < b[0];
        });
        parents_.assign(N, 0);
        iota(parents_.begin(), parents_.end(), 0);
        for(const auto & log : logs) {
            int time = log[0], x = log[1], y = log[2];
            int rx = find(x), ry = find(y);
            if(rx != ry) {
                parents_[rx] = ry;
                if(--N == 1) return time;
            }
        }
        return -1;
    }
    
private:
    int find(int x) {
        return parents_[x] == x ? parents_[x] : (parents_[x] = find(parents_[x]));
    }
    
    vector<int> parents_;
};
