class Solution {
public:
    int balancedString(string s) {
        const int kN = s.length();
        unordered_map<char, int> idxes = {{'Q', 0}, {'W', 1}, {'E', 2}, {'R', 3}};
        int counter[4] = {0};
        for(char ch : s) ++counter[idxes[ch]];
        // the window needs to cover all extra chars
        int covers[4] = {0};
        for(int i = 0; i < 4; ++i) {
            covers[i] = counter[i] > kN / 4 ? counter[i] - kN / 4 : 0;
        }
        int lo = 0;
        int ans = kN;
        auto check = [](int x) {return x <= 0;};
        for(int i = 0; i < kN; ++i) {
            --covers[idxes[s[i]]];
            if (all_of(covers, covers + 4, check)) {
                while (lo <= i && covers[idxes[s[lo]]] + 1 <= 0) {
                    ++covers[idxes[s[lo++]]];
                }
                ans = min(ans, i - lo + 1);
            }
        }
        return ans;
    }
};
