class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        parents.resize(n);
        for(int i = 0; i < n; ++i) parents[i] = i;
        for(auto & p : pairs) {
            unite(p[0], p[1]);
        }
        unordered_map<int, vector<pair<int, char>>> groups;
        for(int i = 0; i < n; ++i) {
            int r = find(i);
            groups[r].push_back({i, s[i]});
        }
        string ans(s);
        for(auto & p : groups) {
            vector<pair<int, char>> & ps = p.second;
            vector<int> idxes;
            vector<char> chars;
            for(auto & item : ps) {
                idxes.push_back(item.first);
                chars.push_back(item.second);
            }
            sort(idxes.begin(), idxes.end());
            sort(chars.begin(), chars.end());
            for(int i = 0; i < idxes.size(); ++i) {
                ans[idxes[i]] = chars[i];
            }
        }
        return ans;
    }
    
private:
    vector<int> parents;
    int find(int x) {
        return parents[x] == x ? x : parents[x] = find(parents[x]);
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            parents[rx] = ry;
        }
    }
};
