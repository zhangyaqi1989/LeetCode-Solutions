class Solution {
public:
    bool queryString(string S, int N) {
        int num = N;
        int ns = S.length();
        int n = 0;
        while (num) {
            ++n;
            num /= 2;
        }
        if (n * ns < N) return false;
        unordered_set<int> seen;
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i < ns + 1 - len; ++i) {
                seen.insert(toBin(S.substr(i, len)));
            }
        }
        // for(int num : seen) cout << num << " ";
        // cout << endl;
        for(int num = 1; num <= N; ++num) {
            // cout << num << endl;
            if (seen.find(num) == seen.end()) return false;
        }
        return true;
    }
    
    int toBin(string S) {
        int ans = 0;
        for(char ch : S) {
            ans = ans * 2 + (ch == '1' ? 1 : 0);
        }
        return ans;
    }
};
