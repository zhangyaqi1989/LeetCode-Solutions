class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for(auto ch : s) m[ch]++;
        for(auto ch : t)
        {
            if (m[ch] > 0) m[ch]--;
            else return ch;
        }
    }
};