class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        const int ns = S.length(), n = indexes.size();
        vector<int> js(n);
        iota(js.begin(), js.end(), 0);
        sort(js.begin(), js.end(), [&](int i, int j) {
            return indexes[i] > indexes[j];
        });
        for(int i = 0; i < n; ++i) {
            int j = js[i];
            int idx = indexes[j];
            string src = sources[j];
            string dst = targets[j];
            int m = src.length();
            if (S.substr(idx, m) == src) {
                S = S.substr(0, idx) + dst + S.substr(idx + m);
            }
        }
        return S;
    }
};
