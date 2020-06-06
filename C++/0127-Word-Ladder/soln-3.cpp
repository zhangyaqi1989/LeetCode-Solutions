class Solution {
public:
    int ladderLength(string source, string target, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(target)) return 0;
        vector<string> frontier = {source};
        unordered_set<string> seen = {source};
        int steps = 1;
        const int kN = source.length();
        while(!frontier.empty()) {
            vector<string> next_level;
            for(string word : frontier) {
                if (word == target) return steps;
                for(int i = 0; i < kN; ++i) {
                    char old_ch = word[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        word[i] = ch;
                        if (seen.find(word) == seen.end() && words.find(word) != words.end()) {
                            seen.insert(word);
                            next_level.push_back(word);
                        }
                        word[i] = old_ch;
                    }
                }
            }
            swap(next_level, frontier);
            ++steps;
        }
        return 0;
    }
};
