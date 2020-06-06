class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        string token;
        int cnt = 0;
        map<char, string> m1;
        map<string, char> m2;
        while (iss >> token) {
            if (cnt >= pattern.length()) return false;
            char ch = pattern[cnt];
            auto it1 = m1.find(ch);
            if (it1 != m1.end()) {
                if (((it1->second) != token) || m2.find(token) == m2.end() || m2[token] != ch) return false;
            } else {
                if (m2.find(token) != m2.end()) return false;
                m1[ch] = token;
                m2[token] = ch;
            }
            ++cnt;
            // cout << token << endl;
        }
        return cnt == pattern.length();
    }
};
