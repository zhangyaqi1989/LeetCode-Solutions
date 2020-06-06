class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false;
        int n = org.size();
        vector<int> pos(n + 1, 0);
        vector<int> flags(n + 1, 0);
        int toMatch = n - 1;
        for(int i = 0; i < n; ++i) pos[org[i]] = i;
        int entered = false;
        for(const auto & seq : seqs)
        {
            for(int i = 0; i < seq.size(); ++i)   
            {
                entered = true;
                if(seq[i] <= 0 || seq[i] > n) return false;
                if(i == 0) continue;
                int x = seq[i - 1], y = seq[i];
                if(pos[x] >= pos[y]) return false;
                if(flags[x] == 0 && pos[y] == pos[x] + 1) flags[x] = 1, --toMatch;
            }
        }
        return toMatch == 0 && entered;
        
    }
};