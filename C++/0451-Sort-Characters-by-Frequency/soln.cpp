class Solution {
public:
    string frequencySort(string s) {
        int count[256] = {0};
        for(char ch : s) ++count[ch];
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (count[a] == count[b]) return a < b;
            else return count[a] > count[b];
            });
        return s;
    }
};
