class Solution {
    
    public int largestComponentSize(int[] A) {
        int n = A.length;
        parents = new int[n];
        sizes = new int[n];
        mx_size = 1;
        ArrayList<Integer> [] factors = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            sizes[i] = 1;
            factors[i] = new ArrayList<>();
            int x = A[i];
            int f = 2;
            while (f * f <= x) {
                if (x % f == 0) {
                    while(x % f == 0) x /= f;
                    factors[i].add(f);
                }
                ++f;
            }
            if (x > 1) factors[i].add(x);
        }
        Map<Integer, Integer> prime_to_idx = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            ArrayList<Integer> fs = factors[i];
            for(int x : fs) {
                if (!prime_to_idx.containsKey(x)) {
                    prime_to_idx.put(x, i);
                } else {
                    unite(i, prime_to_idx.get(x));
                }
            }
        }
        return mx_size;
    }
    
    private int [] parents;    
    private int [] sizes;
    private int mx_size;
    
    private int find(int x) {
        if (parents[x] == x) return x;
        parents[x] = find(parents[x]);
        return parents[x];
    }
    
    private void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            parents[rx] = ry;
            sizes[ry] += sizes[rx];
            mx_size = Math.max(mx_size, sizes[ry]);
        }
    }
}
