class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        for(const auto & p : pairs) {
            string x = p[0];
            string y = p[1];
            unite(x, y);
        }
        const int n = words1.size();
        for(int i = 0; i < n; ++i) {
            if (find(words1[i]) != find(words2[i])) return false;
        }
        return true;
    }
    
private:
    string find(string x) {
        if (parents_.find(x) == parents_.end()) {
            parents_[x] = x;
            sizes_[x] = 1;
        }
        return parents_[x] == x ? x : parents_[x] = find(parents_[x]);
    }
    
    void unite(string x, string y) {
        string rx = find(x);
        string ry = find(y);
        if (rx != ry) {
            if (sizes_[rx] > sizes_[ry]) swap(rx, ry);
            sizes_[ry] += sizes_[rx];
            parents_[rx] = ry;
        }
        
    }

    unordered_map<string, string> parents_;
    unordered_map<string, int> sizes_;
};
