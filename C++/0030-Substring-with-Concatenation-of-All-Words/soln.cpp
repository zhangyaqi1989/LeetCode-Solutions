class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counter;
        for(auto & word : words) counter[word]++;
        vector<int> idxes;
        int nwords = words.size();
        if(nwords == 0) return {};
        int len = words[0].length();
        for(int i = 0; i < s.length() - nwords * len + 1; ++i) {
            int j = 0;
            unordered_map<string, int> seen;
            for(; j < nwords; ++j) {
                string word = s.substr(i + j * len, len);
                if(counter.find(word) != counter.end()) {
                    seen[word]++;
                    if(seen[word] > counter[word])
                        break;
                } else {
                    break;
                }
            }
            if (j == nwords) idxes.push_back(i);
        }
        return idxes;
    }
};
