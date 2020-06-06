class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> counter;
        for(char ch : s) {
            ++counter[ch];
        }
        for(auto & p : counter) {
            if (p.second < k) {
                int i = 0;
                int ans = 0;
                while (i < s.length()) {
                    auto idx = s.find(p.first, i);
                    if (idx == i) {
                        ++i;
                        continue;
                    }
                    if (idx == string::npos) {
                        ans = max(ans, longestSubstring(s.substr(i, s.length() - i), k));
                        return ans;
                    } else {
                        ans = max(ans, longestSubstring(s.substr(i, idx - i), k));
                        i = idx + 1;
                    }
                }
                return ans;
            }
        }
        return s.length();
    }
};
