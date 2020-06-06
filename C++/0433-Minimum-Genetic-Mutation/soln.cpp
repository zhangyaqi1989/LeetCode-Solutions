class Solution {
public:
    int minMutation(string start, string target, vector<string>& bank) {
        unordered_set<string> words(bank.begin(), bank.end());
        if (words.find(target) == words.end()) return -1;
        int nsteps = 0;
        unordered_set<string> s1, s2;
        s1.insert(start);
        s2.insert(target);
        string choices = "ACGT";
        while (!s1.empty() && !s2.empty()) {
            if (s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> s;
            for(const string & word : s1) {
                string temp(word);
                for(int i = 0; i < 8; ++i) {
                    char old_ch = temp[i];
                    for(char ch : choices) {
                        if (ch == old_ch) continue;
                        temp[i] = ch;
                        if (s2.find(temp) != s2.end()) return nsteps + 1;
                        auto it = words.find(temp);
                        if (it != words.end()) {
                            words.erase(it);
                            s.insert(temp);
                        }
                    }
                    temp[i] = old_ch;
                }
            }
            swap(s, s1);
            ++nsteps;
        }
        return -1;
    }
};
