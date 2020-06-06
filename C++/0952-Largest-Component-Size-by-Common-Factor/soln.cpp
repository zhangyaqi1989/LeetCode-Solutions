typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i = (s); i < (t); i++)
#define FILL(x,v) memset(x, v, sizeof(x))
#define MAXN 100005

int parent[MAXN], cnt[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionset(int i, int j) {
    int ri = find(i);
    int rj = find(j);
    if (ri == rj) return;
    parent[ri] = rj;
    cnt[rj] += cnt[ri];
}


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        map<int, VI> factors;
        int n = A.size();
        REP(i,0,n) {
            parent[i] = i;
            cnt[i] = 1;
        }
        
        REP(i,0,n) {
            int x = A[i];
            // cout << x << "H" << endl;
            for (int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    while(x % d == 0) x /= d;
                    factors[d].push_back(i);
                }
            }
            if (x > 1) factors[x].push_back(i);
        }
        
        for (auto & pair : factors) {
            auto & v = pair.second;
            int k = v.size();
            REP(i,0,k-1) {
                // cout << v[i] << " " << v[i + 1] << endl;
                unionset(v[i], v[i + 1]);
                // for(int j = 0; j < n; ++j)
                //     cout << cnt[j] << " ";
                // cout << endl;
                // for(int j = 0; j < n; ++j)
                //     cout << parent[j] << " ";
                // cout << endl;
            }
        }
        int ans = 0;
        REP(i,0,n) ans = max(ans, cnt[find(i)]);
        // REP(i,0,n) cout << cnt[i] << endl;
        // for(int j = 0; j < n; ++j)
        //     cout << parent[j] << " ";
        // cout << endl;
        return ans;
    }
};