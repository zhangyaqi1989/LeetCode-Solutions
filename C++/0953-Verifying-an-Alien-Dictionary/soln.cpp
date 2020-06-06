auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char dic[26] = {0};
        for(int i = 0; i < 26; ++i) {
            dic[order[i] - 'a'] = i;
        }
        int n = words.size();
        for(int i = 0; i < n - 1; ++i) {
            string a = words[i];
            string b = words[i + 1];
            int m = min(a.length(), b.length());
            bool done = false;
            for(int j = 0; j < m; ++j) {
                if(dic[a[j] - 'a'] < dic[b[j] - 'a']){done = true; break;}
                else if (dic[a[j] - 'a'] > dic[b[j] - 'a']) return false;
            }
            if (!done && a.size() > b.size()) return false; 
        }
        return true;
    }
};
