class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // 26
        // use integer to represent each puzzle
        // if a word contains more than 7 unique chars, we can remove it
        const int kP = puzzles.size();
        const int kW = words.size();
        vector<int> ans;
        ans.reserve(kP);
        unordered_map<int, int> counter;
        for(const auto & word : words) {
            int code = 0;
            for(char ch : word) {
                code |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(code) > 7) continue;
            ++counter[code];
        }
        for(const auto & puzzle : puzzles) {
            int idx = puzzle[0] - 'a';
            int code = (1 << idx);
            int total = (1 << 6);
            int cnt = 0;
            for(int i = 0; i < total; ++i) {
                int c = code;
                for(int j = 0; j < 6; ++j) {
                    if (i & (1 << j)) {
                        c |= (1 << (puzzle[j + 1] - 'a'));
                    }
                }
                auto it = counter.find(c);
                if (it != counter.end()) cnt += it->second;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    // 2^6 = 64
};
