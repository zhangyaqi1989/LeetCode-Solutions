class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<int> parents(n, 0);
        vector<int> sizes(n, 1);
        for(int i = 0; i < n; ++i) parents[i] = i;
        int groups = n;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if (similar(A, i, j)) {
                    int ri = find(i, parents);
                    int rj = find(j, parents);
                    if (ri != rj) {
                        if(sizes[ri] > sizes[rj]) swap(ri, rj);
                        parents[ri] = rj;
                        sizes[rj] += sizes[ri];
                        --groups;
                    }
                }
            }
        }
        return groups;
    }
    
    int similar(vector<string> & A, int i, int j) {
        int cnt = 0;
        int n = A[i].length();
        for(int idx = 0; idx < n; ++idx) {
            if (A[i][idx] != A[j][idx]) {
                ++cnt;
                if (cnt > 2) return false;
            }
        }
        return true;
    }
    
    int find(int x, vector<int> & parents) {
        return parents[x] == x ? x : parents[x] = find(parents[x], parents);
    }
};
