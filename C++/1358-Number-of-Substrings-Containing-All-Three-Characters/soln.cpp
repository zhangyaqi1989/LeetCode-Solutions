class Solution {
public:
    int numberOfSubstrings(string str) {
        int i = 0;
        unordered_map<char, int> window;
        int ans = 0;
        for(char ch : str) {
            ++window[ch];
            if (window.size() == 3) {
                while(window.find(str[i]) != window.end() && window[str[i]] > 1) {
                    --window[str[i++]];
                }
                ans += i + 1;
            }
        }
        return ans;
    }
};
