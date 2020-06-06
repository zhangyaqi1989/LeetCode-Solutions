ass Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        mx_size = 1;
        parents.resize(n);
        sizes.resize(n);
        vector<vector<int>> factors(n);
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
            sizes[i] = 1;
            int x = A[i];
            int f = 2;
            while (f * f <= x) {
                if (x % f == 0) {
                    while (x % f == 0) x /= f;
                    factors[i].push_back(f);
                }
                ++f;
            }
            if (x > 1) factors[i].push_back(x);
        }
        unordered_map<int, int> prime_to_idx;
        for(int i = 0; i < n; ++i) {
            auto & fs = factors[i];
            for(int f : fs) {
                if (prime_to_idx.find(f) == prime_to_idx.end()) {
                    prime_to_idx[f] = i;
                } else {
                    unite(i, prime_to_idx[f]);
                }
            }
        }
        return mx_size;
    }

    
private:
    vector<int> parents;
    vector<int> sizes;
    int mx_size;
    int find(int x) {
        return parents[x] == x ? x : parents[x] = find(parents[x]);
    }
    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            parents[rx] = ry;
            sizes[ry] += sizes[rx];
            mx_size = max(mx_size, sizes[ry]);
        }
    }
};
