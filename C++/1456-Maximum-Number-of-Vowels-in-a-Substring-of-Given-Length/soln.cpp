class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "AEIOUaeiou";
        int mx = 0;
        int window = 0;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            window += vowels.find(s[i]) != string::npos;
            if(i >= k) window -= vowels.find(s[i - k]) != string::npos;
            if(i >= k - 1) mx = max(mx, window);
        }
        return mx;
    }
};
