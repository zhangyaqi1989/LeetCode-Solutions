class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        } else {
            string ans = S;
            char start = S[0];
            int n = S.length();
            for(int i = 1; i < n; ++i) {
                if (S[i] > start) continue;
                string temp = S.substr(i) + S.substr(0, i);
                if (temp < ans) {
                    ans = temp;
                    start = temp[0];
                }
            }
            return ans;
        }
    }
};
