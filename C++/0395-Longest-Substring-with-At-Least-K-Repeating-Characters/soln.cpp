class Solution {
public:
    int longestSubstring(string s, int k) {
        // cout << s << endl;
        int counter[26] = {0};
        for(char ch : s) {
            ++counter[ch - 'a'];
        }
        bool enough = false;
        for(int i = 0; i < 26; ++i) {
            if (counter[i] >= k) {
                enough = true;
                break;
            }
        }
        // cout << enough << endl;
        if (!enough) return 0;
        int ans = 0;
        bool valid = true;
        for(int i = 0; i < 26; ++i) {
            if (counter[i] > 0 && counter[i] < k) {
                valid = false;
                int j = 0;
                char ch = i + 'a';
                // cout << ch << endl;
                while (j < s.length()) {
                    auto idx = s.find(ch, j);
                    if (idx == string::npos) {
                        ans = max(ans, longestSubstring(s.substr(j), k));
                        j = s.length();
                    } else {
                        if (idx != j)
                            ans = max(ans, longestSubstring(s.substr(j, idx - j), k));
                        j = idx + 1;
                    }
                }
                return ans;
            }
        }
        
        return s.length();
        
    }
};
