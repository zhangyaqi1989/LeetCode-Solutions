class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        // construct
        if (seqs.empty() || all_of(seqs.begin(), seqs.end(), [](const vector<int> seq) {return seq.empty();})) return false;
        const int n = org.size();
        vector<int> indegrees(n + 1, 0);
        vector<vector<int>> outs(n + 1);
        for(const auto & seq : seqs) {
            const int m = seq.size();
            if (m != 0 && (seq[0] < 1 || seq[0] > n)) return false;
            for(int i = 1; i < m; ++i) {
                int u = seq[i - 1], v = seq[i];
                if (u < 1 || u > n || v < 1 || v > n || u == v) return false;
                ++indegrees[v];
                outs[u].push_back(v);                
            }
        }
        vector<int> frees;
        for(int i = 1; i <= n; ++i) {
            if (!indegrees[i]) frees.push_back(i);
        }
        int idx = 0;
        while (!frees.empty()) {
            if (frees.size() > 1) return false;
            int u = frees.back();
            frees.pop_back();
            if (idx >= n || org[idx++] != u) return false;
            for(int v : outs[u]) {
                if (--indegrees[v] == 0) frees.push_back(v);
            }
        }
        return idx == n;
    }
};
