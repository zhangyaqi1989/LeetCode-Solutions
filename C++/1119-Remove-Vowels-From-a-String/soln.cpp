class Solution {
public:
    string removeVowels(string S) {
        string ans;
        for(char ch : S) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
            ans += ch;
        }
        return ans;
    }
};
