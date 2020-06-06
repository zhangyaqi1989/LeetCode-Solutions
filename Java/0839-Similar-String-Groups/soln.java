class Solution {
    public int numSimilarGroups(String[] A) {
        int n = A.length;
        int [] parents = new int [n];
        int [] sizes = new int [n];
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            sizes[i] = 1;
        }
        int groups = n;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if (similar(A, i, j)) {
                    int ri = find(i, parents);
                    int rj = find(j, parents);
                    if (ri != rj) {
                        --groups;
                        if (sizes[ri] > sizes[rj]) {
                            int temp = ri;
                            ri = rj;
                            rj = temp;
                        }
                        parents[ri] = rj;
                        sizes[rj] += sizes[ri];
                    }
                }
            }
        }
        return groups;
        
    }
    
    public int find(int x, int[] parents) {
        if (x == parents[x]) return x;
        else {
            parents[x] = find(parents[x], parents);
            return parents[x];
        }
    }
    
    public boolean similar(String[] A, int i, int j) {
        int cnt = 0;
        for(int idx = 0; idx < A[i].length(); ++idx) {
            if (A[i].charAt(idx) != A[j].charAt(idx)) {
                ++cnt;
                if (cnt > 2) return false;
            }
        }
        return true;
    }
}
