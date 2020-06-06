int parents[26];

int find(int x) {
    return parents[x] == x ? x : parents[x] = find(parents[x]);
}

void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) parents[rx] = parents[ry];
}

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; ++i) parents[i] = i;
        vector<pair<int, int>> noeqs;
        for(auto & eq : equations) {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            char op = eq[1];
            if (op == '=') unite(x, y);
            else noeqs.push_back({x, y});
        }
        for(auto &it : noeqs) {
            if (find(it.first) == find(it.second)) return false;
        }
        return true;
    }
};
