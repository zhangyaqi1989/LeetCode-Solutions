class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int shift = 0;
        int n = indexes.size();
        vector<pair<int, int>> sorted;
        for(int i = 0; i < n; ++i) sorted.emplace_back(indexes[i], i);
        sort(sorted.begin(), sorted.end());
        for(auto & p : sorted) {
            int idx = p.first;
            int j = p.second;
            string source = sources[j];
            if (S.substr(idx + shift, source.length()) == source) {
                S = S.substr(0, idx + shift) + targets[j] + S.substr(idx + shift + source.length());
                shift += targets[j].length() - source.length();
            }
        }
        return S;
    }
};
