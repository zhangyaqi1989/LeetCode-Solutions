class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        unordered_set<char> vowels_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto ch : s)
            if(vowels_set.count(ch))
                vowels.push_back(ch);
        string ans = s;
        for(int i = 0; i < ans.size(); ++i)
            if(vowels_set.count(ans[i]))
            {
                ans[i] = vowels.back();
                vowels.pop_back();
            }
        return ans;       
    }
};