bool mycmp(const string & s, const string & t) {
    if (s.length() == t.length()) return s < t;
    else return s.length() > t.length();
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), mycmp);
        for(string & t : d) {
            if (valid(s, t)) return t;
        }
        return "";
    }
    
    bool valid(string s, string t) {
        // return if t is a subsequence of s
        int j = 0, nt = t.length();
        for(char ch : s) {
            if (ch == t[j]) {
                ++j;
                if (j == nt) return true;
            }
        }
        return false;
    }
    
    
};
