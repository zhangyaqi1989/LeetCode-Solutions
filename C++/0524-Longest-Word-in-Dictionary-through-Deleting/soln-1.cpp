class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<int> idxes((int) d.size());
        iota(idxes.begin(), idxes.end(), 0);
        sort(idxes.begin(), idxes.end(), [&](int i, int j) 
             {return d[i].length() == d[j].length() ? i < j : d[i].length() > d[j].length();});
        for(int idx : idxes) {
            string & word = d[idx];
            int ns = s.length(), nw = word.length();
            int j = 0;
            for(int i = 0; i < ns; ++i) {
                if (s[i] == word[j]) {
                    if (++j == nw) return word;
                }
            }
        }
        return "";
    }
};
