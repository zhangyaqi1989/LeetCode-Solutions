class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        const int n = A.size();
        vector<vector<int>> factors(n);
        for(int i = 0; i < n; ++i) {
            int num = A[i];
            for(int t = 2; t * t <= num; ++t) {
                if(num % t == 0) {
                    factors[i].push_back(t);
                    while(num % t == 0) num /= t;
                }
            }
            if (num > 1) factors[i].push_back(num);
        }
        unordered_map<int, int> memo;
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0);
        vector<int> sizes(n, 1);
        int mx = 1;
        for(int i = 0; i < n; ++i) {
            for(auto t : factors[i]) {
                auto it = memo.find(t);
                if (it == memo.end()) memo[t] = i;
                else {
                    int x = i, y = it->second;
                    int rx = find(x, parents), ry = find(y, parents);
                    if (rx != ry) {
                        if(sizes[ry] < sizes[rx]) swap(rx, ry);
                        parents[rx] = ry;
                        sizes[ry] += sizes[rx];
                        mx = max(mx, sizes[ry]);
                    }
                }
            }
        }
        return mx;
    }
    
private:
    int find(int x, vector<int> & parents) {
        return parents[x] == x ? x : parents[x] = find(parents[x], parents);
    }
};
