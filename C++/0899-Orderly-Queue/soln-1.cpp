class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        } else {
            string ans(S);
            const int n = S.length();
            for(int i = 0; i < n - 1; ++i) {
                rotate(S.begin(), S.begin() + 1, S.end());
                if (S < ans) ans = S;
            }
            return ans;
        }
    }
};
