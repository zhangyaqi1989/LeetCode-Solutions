class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;
        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        words.erase(endWord);
        int steps = 0;
        while (!s1.empty() && !s2.empty()) {
            if (s2.size() < s1.size()) swap(s1, s2);
            unordered_set<string> s;
            // transform s1
            ++steps;
            for(string word : s1) {
                for(int i = 0; i < word.length(); ++i) {
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        string temp(word);
                        temp[i] = ch;
                        if (s2.find(temp) != s2.end()) return steps + 1;
                        if (words.find(temp) != words.end()) {
                            words.erase(temp);
                            s.insert(temp);
                        }
                    }
                }
            }
            swap(s1, s);
        }
        return 0;
    }
};
