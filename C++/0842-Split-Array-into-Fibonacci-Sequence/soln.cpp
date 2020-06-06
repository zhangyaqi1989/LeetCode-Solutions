class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        int n = S.length();
        for(int i = 1; i <= n / 2; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                string str_a = S.substr(0, i), str_b = S.substr(i, j - i);
                if (valid(str_a) && valid(str_b)) {
                    int a = stoi(str_a), b = stoi(str_b);
                    ans.clear();
                    ans.push_back(a);
                    ans.push_back(b);
                    int idx = j;
                    while (idx < n) {
                        long long ll_c = (long long) a + b;
                        if (ll_c > INT_MAX) break;
                        int c = a + b;
                        string str_c = to_string(c);
                        if (S.substr(idx, str_c.length()) != str_c) break;
                        idx = idx + str_c.length();
                        a = b;
                        b = c;
                        ans.push_back(c);
                    }
                    
                    if (idx == n && ans.size() >= 3) return ans;
                }
            }
        }
        return {};
    }
    
    bool valid(string S) {
        if (S.length() > 10 || (S.length() > 1 && S[0] == '0')) return false;
        long long num = stoll(S);
        if (num > INT_MAX) return false;
        return true;
    }
};
