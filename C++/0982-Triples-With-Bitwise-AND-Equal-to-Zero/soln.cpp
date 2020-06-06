auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> v(1 << 16, -1);
        int ans = 0;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int s = A[i] & A[j];
                int cnt = 0;
                if (v[s] == -1) {
                    for(int k = 0; k < n; ++k) {
                        if ((s & A[k]) == 0)
                            cnt += 1;
                    }
                    v[s] = cnt;
                    ans += cnt;
                } else 
                    ans += v[s];
            }
        }
        return ans;
    }
};
