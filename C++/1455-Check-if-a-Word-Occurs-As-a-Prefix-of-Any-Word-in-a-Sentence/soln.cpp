class Solution {
public:
    int isPrefixOfWord(string sentence, string p) {
        istringstream iss(sentence);
        int idx = 1;
        string word;
        int np = p.length();
        while(iss >> word) {
            if(word.length() >= p.length() && word.substr(0, np) == p) {
                return idx;
            }
            ++idx;
        }
        return -1;
    }
};
