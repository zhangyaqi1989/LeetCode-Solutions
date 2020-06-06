class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<pair<int, int>> sorted;
        for(int i = 0; i < n; ++i) sorted.emplace_back(indexes[i], i);
        sort(sorted.rbegin(), sorted.rend());
        for(auto & p : sorted) {
            int idx = p.first;
            int j = p.second;
            string source = sources[j];
            if (S.substr(idx, source.length()) == source) {
                S = S.substr(0, idx) + targets[j] + S.substr(idx + source.length());
            }
        }
        return S;
    }
};
