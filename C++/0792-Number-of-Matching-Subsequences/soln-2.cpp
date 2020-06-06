class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt = 0;
        // cur_char -> (nxt_idx, word_idx)
        unordered_map<char, vector<pair<int, int>>> dict;
        const int kNWords = words.size();
        for(int i = 0; i < kNWords; ++i) {
            const string & word = words[i];
            dict[word[0]].emplace_back(1, i);
        }
        for(char ch : S) {
            auto it = dict.find(ch);
            if (it == dict.end()) continue;
            auto pairs = it->second;
            dict.erase(it);
            for(auto & p : pairs) {
                int next_idx = p.first, word_idx = p.second;
                if (next_idx == static_cast<int>(words[word_idx].size())) ++cnt;
                else {
                    char next_ch = words[word_idx][next_idx];
                    dict[next_ch].emplace_back(next_idx + 1, word_idx);
                }
            }
        }
        return cnt;
    }
};
