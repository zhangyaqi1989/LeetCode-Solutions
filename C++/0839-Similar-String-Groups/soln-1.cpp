class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        ngroups = n;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if (isSimilar(A, i, j)) {
                    int ri = find(i);
                    int rj = find(j);
                    if (ri != rj) {
                        --ngroups;
                        parents[ri] = rj;
                    }
                }
            }
        }
        return ngroups;
    }
    
private:
    int find(int x) {
        return parents[x] == x ? x : parents[x] = find(parents[x]);
    }
    bool isSimilar(vector<string> & A, int i, int j) {
        string wi = A[i], wj = A[j];
        int n = wi.length();
        int cnt = 0;
        for(int k = 0; k < n; ++k) {
            if (wi[k] != wj[k]) {
                if (++cnt > 2) {
                    return false;
                }
            }
        }
        return true;
    }
    
    vector<int> parents;
    int ngroups;
};
