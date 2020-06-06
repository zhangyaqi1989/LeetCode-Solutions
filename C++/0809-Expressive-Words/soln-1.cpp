class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        // size of the group is 3 or more
        vector<pair<char, int>> pattern = process(S);
        return count_if(words.begin(), words.end(), [&](const string & word) {return valid(word, pattern);});
    }
    
private:
    bool valid(const string & word, const vector<pair<char, int>> & pattern) {
        int cnt = 0, lo = 0;
        const int n = word.length();
        int idx = 0;
        for(int i = 0; i < n; ++i) {
            if(word[i] == word[lo]) ++cnt;
            else {
                if(idx >= pattern.size()) return false;
                if(word[lo] != pattern[idx].first || (cnt > pattern[idx].second) || (cnt < pattern[idx].second && pattern[idx].second < 3)) return false;
                lo = i;
                cnt = 1;
                ++idx;
            }
        }
        if(idx >= pattern.size()) return false;
        if(word[lo] != pattern[idx].first || (cnt > pattern[idx].second) || (cnt < pattern[idx].second && pattern[idx].second < 3)) return false;
        return ++idx == pattern.size();
    }
    vector<pair<char, int>> process(const string & s) {
        vector<pair<char, int>> pairs;
        int cnt = 0, lo = 0;
        const int n = s.length();
        for(int i = 0; i < n; ++i) {
            if (s[i] == s[lo]) ++cnt;
            else {
                pairs.emplace_back(s[lo], cnt);
                lo = i;
                cnt = 1;
            }
        }
        pairs.emplace_back(s[lo], cnt);
        return pairs;
    }
};
