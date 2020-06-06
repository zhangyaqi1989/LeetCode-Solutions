class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        int ns = s.length(), nw = words[0].length();
        unordered_map<string, int> counter;
        for(string word : words) ++counter[word];
        int total_len = nw * words.size();
        for (int i = 0; i < ns - total_len + 1; ++i) {
            int j = i;
            bool valid = true;
            unordered_map<string, int> seen;
            while (j < i + total_len) {
                string word = s.substr(j, nw);
                if (counter[word] != 0 && seen[word] < counter[word]) {
                    ++seen[word];
                    j += nw;
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.push_back(i);
        }
        return ans;
    }
};
