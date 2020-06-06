const int N = 4000;
int parents[N];


int find(int x) {
    return parents[x] == x ? x : parents[x] = find(parents[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) parents[rx] = parents[ry];
}

class Solution {
    
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        // This is UF problem
        map<string, int> m;
        int cnt = 0;
        for(auto it : pairs) {
            string a = it.first, b = it.second;
            if (m.find(a) == m.end()) {
                m[a] = cnt++;
            }
            if (m.find(b) == m.end()) {
                m[b] = cnt++;
            }
        }
        for(int i = 0; i < N; ++i) parents[i] = i;
        for(auto it : pairs) {
            unite(m[it.first], m[it.second]);
        }
        int n1 = words1.size(), n2 = words2.size();
        if (n1 != n2) return false;
        for(int i = 0; i < n1; ++i) {
            string word1 = words1[i], word2 = words2[i];
            if (word1 == word2) continue;
            else {
                // if (word1.length() != word2.length()) return false;
                auto it1 = m.find(word1);
                auto it2 = m.find(word2);
                if (it1 == m.end() or it2 == m.end()) return false;
                int i1 = it1->second;
                int i2 = it2->second;
                // cout << i1 << " " << i2 << endl;
                if (find(i1) != find(i2)) return false;
            }
        }
        return true;
    }
};
