class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        vector<int> parent;
        for (int i = 0; i < A.size(); ++i)
            parent.push_back(i);
        vector<int> ranks(A.size(), 1);
        
        unordered_map<int, vector<int>> factors;
        for(int i = 0; i < A.size(); ++i) {
            int x = A[i];
            for(int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    while (x % d == 0) x /= d;
                    factors[d].push_back(i);
                }
            }
            if (x > 1) factors[x].push_back(i);
        }
        
        for (auto & pair : factors) {
            auto & v = pair.second;
            int k = v.size();
            for(int i = 0; i < k - 1; ++i) {
                // cout << v[i] << " " << v[i + 1] << endl;
                union_two(v[i], v[i + 1], parent, ranks);
            }
        }
        
        // for(int p : parent)
        //     cout << p << " ";
        // cout << endl;

        for (int i = 0; i < A.size(); ++i)
            find(i, parent);
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i)
            m[parent[i]] += 1;
        int ans = INT_MIN;
        for (auto & pair : m)
            if (pair.second > ans)
                ans = pair.second;
        return ans;
    }
    
    int find(int i, vector<int> & parent) {
        if (parent[i] != i)
            parent[i] = find(parent[i], parent);
        return parent[i];
    }
    
    void union_two(int i, int j, vector<int> & parent, vector<int> & ranks) {
        int iroot = find(i, parent);
        int jroot = find(j, parent);
        if (ranks[iroot] < ranks[jroot]) {
            parent[iroot] = jroot;
            ranks[jroot] += ranks[iroot];
        
        } else if (ranks[iroot] > ranks[jroot]) {
            parent[jroot] = iroot;
            ranks[iroot] = ranks[jroot];
        } else {
            parent[jroot] = iroot;
            ranks[iroot] += jroot;
        }
    }
};