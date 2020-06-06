class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        int step = 1;
        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        while (!s1.empty() && !s2.empty()) {
            if (s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> s;
            ++step;
            for(string word : s1) {
                int n = word.size();
                for(int i = 0; i < n; ++i) {
                    for (int j = 0; j < 26; ++j) {
                        string new_word = word.substr(0, i) + string(1, 'a' + j) + word.substr(i + 1);
                        if (s2.count(new_word)) return step;
                        auto it = words.find(new_word);
                        if (it != words.end()) {
                            words.erase(it);
                            s.insert(new_word);
                        }
                    }
                }
            }
            swap(s1, s);
            
        }
        return 0;
    }
};
