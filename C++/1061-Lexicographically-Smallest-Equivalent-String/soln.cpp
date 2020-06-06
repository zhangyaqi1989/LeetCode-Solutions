int parents[26];
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        for(int i = 0; i < 26; ++i) parents[i] = i;
        int n = A.length();
        for(int i = 0; i < n; ++i) {
            int x = A[i] - 'a', y = B[i] - 'a';
            unite(x, y);
        }
        string res = "";
        for(char ch : S) {
            res += (char) ('a' + find(ch - 'a'));
        }
        return res;
    }
    
    int find(int x) {
        return x == parents[x] ? parents[x] : parents[x] = find(parents[x]);
    }
    
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx < ry) parents[ry] = rx;
        else parents[rx] = ry;
    }
};
