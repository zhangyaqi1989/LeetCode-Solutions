class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "", s = "";
        for(auto ch : S) {
            if (isalnum(ch))
                s += toupper(ch);
        }
        // cout << s << endl;
        int n = s.length();
        int q = n / K, r = n % K;
        if (r != 0) {
            ans += s.substr(0, r);
            if (q > 0) ans += "-";
        }
        int idx = r;
        for(int i = 0; i < q; ++i) {
            ans += s.substr(idx, K);
            idx += K;
            if (i != q - 1) ans += "-";
        }
        return ans;
        
    }
};
