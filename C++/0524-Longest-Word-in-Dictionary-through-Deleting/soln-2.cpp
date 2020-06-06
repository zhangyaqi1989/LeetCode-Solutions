class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string & a, const string & b) {
           return a.length() > b.length(); 
        });
        int mx = -1;
        string ans = "";
        for(int i = 0; i < (int) d.size(); ++i) {
            if (valid(s, d[i])) {
                if ((int) d[i].length() > mx || ((int) d[i].length() == mx && d[i] < ans)) {
                    ans = d[i];
                    mx = d[i].length();
                }
            }
            if ((int) d[i].length() < mx) break;
        }
        return ans;
    }
    
private:
    bool valid(const string & s, const string & t) {
        if (t.empty()) return true;
        const int ns = s.length(), nt = t.length();
        int i = 0, j = 0;
        while (i < ns) {
            if (s[i] == t[j]) {
                if (++j == nt) return true;
            }
            ++i;
        }
        return false;
    }
};
